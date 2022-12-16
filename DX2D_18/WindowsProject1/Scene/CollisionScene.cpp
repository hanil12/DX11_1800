#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rect = make_shared<RectCollider>(Vector2(100.0f,100.0f ));
	_rect->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };

	_circle = make_shared<CircleCollider>(50);
	_circle->GetTransform()->GetPos() = { CENTER_X + 100, CENTER_Y };
	_circle->SetGREEN();
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_rect->Update();
	_circle->Update();
}

void CollisionScene::Render()
{
	ImGui::SliderFloat("PosX", &_rect->GetTransform()->GetPos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_rect->GetTransform()->GetPos()._y, 0, WIN_HEIGHT);

	_rect->Render();
	_circle->Render();
}
