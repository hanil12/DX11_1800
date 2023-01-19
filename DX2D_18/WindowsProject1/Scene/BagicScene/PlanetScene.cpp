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
	_earth->Getpos().x += 200;
	_earthTrans->GetPos().x += 200;

	_moon->SetParent(_earthTrans);
	_moon->Getpos().x += 120;
}

PlanetScene::~PlanetScene()
{
}

void PlanetScene::Update()
{
	if (KEY_PRESS('O'))
	{
		_sun->GetScale().x -= 0.5f * DELTA_TIME;
		_sunTrans->GetScale().x -= 0.5f * DELTA_TIME;
	}

	if (KEY_PRESS('P'))
	{
		_sun->GetScale().x += 0.5f * DELTA_TIME;
		_sunTrans->GetScale().x += 0.5f * DELTA_TIME;
	}

	if (KEY_PRESS(VK_LEFT))
	{
		_sun->Getpos().x -= 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos().x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_RIGHT))
	{
		_sun->Getpos().x += 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos().x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_UP))
	{
		_sun->Getpos().y += 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos().y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(VK_DOWN))
	{
		_sun->Getpos().y -= 0.5f * DELTA_TIME * 100;
		_sunTrans->GetPos().y -= 0.5f * DELTA_TIME * 100;
	}

	_sun->GetAngle() += 0.0005f * DELTA_TIME * 100; // ����
	_sunTrans->GetAngle() += 0.001f * DELTA_TIME * 100; // ����
	_earth->GetAngle() += 0.0005f * DELTA_TIME * 100; // ����
	_earthTrans->GetAngle() += 0.001f * DELTA_TIME * 100; // ����
	_moon->GetAngle() += 0.005f * DELTA_TIME * 100;

	_sun->Getpos() = mousePos;
	_sunTrans->GetPos() = mousePos;

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
