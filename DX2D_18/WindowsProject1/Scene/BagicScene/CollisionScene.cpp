#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rect = make_shared<RectCollider>(Vector2(100.0f,100.0f ));
	_rect->GetTransform()->GetPos() = { CENTER_X, CENTER_Y };

	_circle = make_shared<CircleCollider>(50);
	_circle->GetTransform()->GetPos() = { CENTER_X + 100, CENTER_Y };
	_circle->SetGREEN();


	_circle1 = make_shared<CircleCollider>(50);
	_circle1->GetTransform()->GetPos() = { CENTER_X + 100, CENTER_Y };
	_circle1->SetGREEN();


	_circle2 = make_shared<CircleCollider>(50);
	_circle2->GetTransform()->GetPos() = { CENTER_X + 100, CENTER_Y };
	_circle2->SetGREEN();
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_circle1->GetTransform()->GetPos() = mousePos;

	_circle1->Block(_circle2);

	_circle1->Update();
	_circle2->Update();

	_rect->Update();
	_circle->Update();
}

void CollisionScene::Render()
{
	_rect->Render();
	_circle->Render();

	_circle1->Render();
	_circle2->Render();
}
