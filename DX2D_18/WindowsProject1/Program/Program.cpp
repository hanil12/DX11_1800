#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/PlanetScene.h"

Program::Program()
{
	//_scenes["TextureScene"] = make_shared<TextureScene>();
	_scenes["PlanetScene"] = make_shared<PlanetScene>();
	_curScene = _scenes["PlanetScene"];

	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0.0f, WIN_WIDTH, 0, WIN_HEIGHT, -1.0f, 1.0f);

	_projectBuffer->SetData(projectionM);

	_viewBuffer->Update();
	_projectBuffer->Update();
}

Program::~Program()
{
}

void Program::Update()
{
	// Scene Update();
	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();

	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	AlphaBlendState->SetState();

	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);

	// Scene Render
	_curScene->Render();

	Device::GetInstance()->Present();
}
