#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"

Program::Program()
{
	_scenes["TextureScene"] = make_shared<TextureScene>();
	_curScene = _scenes["TextureScene"];
}

Program::~Program()
{
}

void Program::Update()
{
	// Scene Update();
	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	// Scene Render
	_curScene->Render();

	Device::GetInstance()->Present();
}
