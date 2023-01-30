#include "framework.h"
#include "UIScene.h"

UIScene::UIScene()
{
	_bar = make_shared<HPBar>();
	_bar->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
	_bar->GetTransform()->GetScale() *= 0.5f;
	_bar->GetTransform()->GetScale().y *= 0.7f;
}

UIScene::~UIScene()
{
}

void UIScene::Update()
{
	_bar->Update();
}

void UIScene::Render()
{
}

void UIScene::PostRender()
{
	_bar->Render();

	if (ImGui::Button("-0.1 ratio", { 100,100 }))
	{
		_bar->ratio() -= 0.1f;
	}
}
