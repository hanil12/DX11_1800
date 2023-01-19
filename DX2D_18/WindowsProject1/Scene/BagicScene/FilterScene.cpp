#include "framework.h"
#include "FilterScene.h"

FilterScene::FilterScene()
{
	_quad = make_shared<Quad>(L"2B.png");
	_quad->GetTransform()->GetPos() = { CENTER_X , CENTER_Y };
	_quad->SetPixelShader(ADD_PS(L"Filter/FilterShader"));

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->_data.selected = 1;
	_filterBuffer->_data.value1 = 2;

	_imageSizeBuffer = make_shared<ImageSizeBuffer>();
	_imageSizeBuffer->_data.imageSize = _quad->GetSize();
}

FilterScene::~FilterScene()
{
}

void FilterScene::Update()
{
	_filterBuffer->Update();
	_imageSizeBuffer->Update();
	_quad->Update();
}

void FilterScene::Render()
{
	_filterBuffer->SetPSBuffer(1);
	_imageSizeBuffer->SetPSBuffer(2);
	_quad->Render();
}

void FilterScene::PostRender()
{
	ImGui::SliderInt("Selected", &_filterBuffer->_data.selected, 0, 6);
	ImGui::SliderInt("Value1", &_filterBuffer->_data.value1, 0, 100);
	ImGui::SliderInt("Value2", &_filterBuffer->_data.value2, 0, 100);
	ImGui::SliderInt("Value3", &_filterBuffer->_data.value3, 0, 100);

	if (ImGui::Button("CupScene", ImVec2(50, 50)))
	{
		PrevScene();
	}
}

void FilterScene::PrevScene()
{
	SCENE->ChangeScene("CupHead");
}
