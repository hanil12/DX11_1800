#include "framework.h"
#include "InstancingScene.h"

InstancingScene::InstancingScene()
{
	//for (int i = 0; i < 100; i++)
	//{
	//	shared_ptr<Quad> quad = make_shared<Quad>(L"DDong.png");
	//	quad->GetTransform()->GetPos() = { MathUtility::RandomFloat(0,WIN_WIDTH), MathUtility::RandomFloat(0,WIN_HEIGHT) };
	//	float randomScale = MathUtility::RandomFloat(0, 0.3f);
	//	quad->GetTransform()->GetScale() = { randomScale, randomScale };
	//	_quads.push_back(quad);
	//}

	_quad = make_shared<Quad>(L"DDong.png");
	_quad->SetVertexShader(ADD_VS(L"InstanceVertexShader"));
	_quad->SetPixelShader(ADD_PS(L"InstancePixelShader"));

	_instanceDataes.resize(100);

	for (auto& data : _instanceDataes)
	{
		Transform transform;
		transform.GetPos() = { MathUtility::RandomFloat(0,WIN_WIDTH), MathUtility::RandomFloat(0,WIN_HEIGHT) };
		float randomScale = MathUtility::RandomFloat(0, 0.3f);
		transform.GetScale() = { randomScale ,randomScale };
		transform.SetSRT();

		data.matrix = XMMatrixTranspose(*transform.GetMatrix());
	}

	_transform = make_shared<Transform>();
	_transform->GetPos() = { CENTER_X, CENTER_Y };
	_transform->SetSRT();
	_instanceDataes[0].matrix = XMMatrixTranspose(*_transform->GetMatrix());

	_instancingBuffer = make_shared<VertexBuffer>(_instanceDataes.data(), sizeof(InstanceData), 100,0,true);
}

InstancingScene::~InstancingScene()
{
}

void InstancingScene::Update()
{
	if (KEY_PRESS('W'))
	{
		_transform->GetScale().x += DELTA_TIME;
		_transform->GetScale().y += DELTA_TIME;
		_transform->SetSRT();
		_instanceDataes[0].matrix = XMMatrixTranspose(*_transform->GetMatrix());
	}
}

void InstancingScene::Render()
{
	_instancingBuffer->IASet(1);

	_quad->SetRender();

	DC->DrawIndexedInstanced(6, 100, 0, 0, 0); // DrawCall
}
