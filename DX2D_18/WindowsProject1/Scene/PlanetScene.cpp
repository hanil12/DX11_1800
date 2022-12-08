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
	if (KEY_PRESS(VK_LEFT))
	{
		_sun->Getpos()._x -= 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_RIGHT))
	{
		_sun->Getpos()._x += 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_UP))
	{
		_sun->Getpos()._y += 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_DOWN))
	{
		_sun->Getpos()._y -= 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos()._y -= 0.5f * DELTA_TIME * 100;
	}


	_sun->GetAngle() += 0.0005f * DELTA_TIME * 100; // 자전
	_sunTrans->GetAngle() += 0.001f * DELTA_TIME * 100; // 공전
	_earth->GetAngle() += 0.0005f * DELTA_TIME * 100; // 자전
	_earthTrans->GetAngle() += 0.001f * DELTA_TIME * 100; // 공전
	_moon->GetAngle() += 0.005f * DELTA_TIME * 100;

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
