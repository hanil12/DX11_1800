#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_bullet = make_shared<Cup_Bullet>();
	_player = make_shared<Cup_Player>();
	_bg = make_shared<Cup_Background>();

	_bullet->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_bullet->Update();
	_player->Update();
}

void CupHeadScene::PreRender()
{
	_bg->Render();
}

void CupHeadScene::Render()
{
	_bullet->Render();
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
