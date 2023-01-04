#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_bullet = make_shared<Cup_Bullet>();
	_player = make_shared<Cup_Player>();
	_bg = make_shared<Cup_Background>();

	_bullet->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };

	Camera::GetInstance()->SetTarget(_player->GetTransform());
	Camera::GetInstance()->SetOffSet({ CENTER_X, 160 });
	Camera::GetInstance()->SetLeftBottom(_bg->GetSize() * 0.5f * -1.0f + _bg->GetMainPos());
	Camera::GetInstance()->SetRightTop(_bg->GetSize() * 0.5f + _bg->GetMainPos());
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
