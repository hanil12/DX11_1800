#include "framework.h"
#include "PlanetScene.h"

PlanetScene::PlanetScene()
{
	_sun = make_shared<Planet>("sun.png", Vector2(150,150));
	_earth = make_shared<Planet>("earth.png", Vector2(100, 100));
	_moon = make_shared<Planet>("moon.png", Vector2(50, 50));

	_sunTrans = make_shared<Transform>();
	_earthTrans = make_shared<Transform>();

	_earth->SetParent(_sunTrans);
	_earthTrans->SetParent(_sunTrans);
	_earth->Getpos()._x += 200;
	_earthTrans->GetPos()._x += 200;

	_moon->SetParent(_earthTrans);
	_moon->Getpos()._x += 120;
}

PlanetScene::~PlanetScene()
{
}

void PlanetScene::Update()
{
	_sun->GetAngle() += 0.0005f; // 자전
	_sunTrans->GetAngle() += 0.001f; // 공전
	_earth->GetAngle() += 0.0005f; // 자전
	_earthTrans->GetAngle() += 0.001f; // 공전
	_moon->GetAngle() += 0.005f;

	_sun->Update();
	_earth->Update();
	_moon->Update();

	_sunTrans->Update();
	_earthTrans->Update();
}

void PlanetScene::Render()
{
	_sunTrans->SetWorldBuffer();
	_earthTrans->SetWorldBuffer();

	_sun->Render();
	_earth->Render();
	_moon->Render();
}
