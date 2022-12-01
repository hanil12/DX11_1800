#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"

Program::Program()
{
	_scenes["TextureScene"] = make_shared<TextureScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	// Scene Update();
	_scenes["TextureScene"]->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	// Scene Render
	_scenes["TextureScene"]->Render();

	Device::GetInstance()->Present();
}
