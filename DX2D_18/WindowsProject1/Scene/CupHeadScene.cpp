#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<Cup_Player>();
	_bg = make_shared<Cup_Background>();

	Camera::GetInstance()->SetTarget(_player->GetTransform());
	Camera::GetInstance()->SetOffSet({ CENTER_X, 160 });
	Camera::GetInstance()->SetLeftBottom(_bg->GetSize() * 0.5f * -1.0f + _bg->GetMainPos());
	Camera::GetInstance()->SetRightTop(_bg->GetSize() * 0.5f + _bg->GetMainPos());

	SOUND->Add("bagic_bgm", "Resource/Sound/BGM.mp3", true);
	SOUND->Play("bagic_bgm");
	// Load();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	if (KEY_DOWN(VK_SPACE))
	{
		Camera::GetInstance()->ShakeStart(3.0f, 0.3f);
	}

	_player->Update();
}

void CupHeadScene::PreRender()
{
	_bg->Render();
}

void CupHeadScene::Render()
{
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();

	if (ImGui::Button("Save", ImVec2(50, 50)))
		Save();
	if (ImGui::Button("Load", ImVec2(50, 50)))
		Load();
}

void CupHeadScene::Save()
{
	BinaryWriter writer = BinaryWriter(L"Save/CupHeadInfo.cup");

	Vector2 pos = _player->GetTransform()->GetWorldPos();
	writer.Byte((void*)&pos, sizeof(Vector2));

	vector<Vector2> temp;
	temp.push_back({ 0,0 });
	temp.push_back({ 1,1 });
	temp.push_back({ 2,2 });

	writer.UInt(temp.size());
	writer.Byte(temp.data(), sizeof(Vector2) * temp.size());
}

void CupHeadScene::Load()
{
	BinaryReader reader = BinaryReader(L"Save/CupHeadInfo.cup");

	Vector2 pos;
	Vector2* address = &pos;

	reader.Byte((void**)&address, sizeof(Vector2));
	_player->GetTransform()->GetPos() = pos;

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);
}
