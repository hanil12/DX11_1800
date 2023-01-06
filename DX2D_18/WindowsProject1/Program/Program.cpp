#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/PlanetScene.h"
#include "../Scene/GunGreed.h"
#include "../Scene/CollisionScene.h"
#include "../Scene/AvoidDDong.h"
#include "../Scene/SpriteScene.h"
#include "../Scene/CupHeadScene.h"
#include "../Scene/FilterScene.h"
#include "../Scene/EffectScene.h"

Program::Program()
{
	srand(static_cast<UINT>(time(nullptr)));

	//_scenes["TextureScene"]		 = make_shared<TextureScene>();
	//_scenes["PlanetScene"]		 = make_shared<PlanetScene>();
	//_scenes["GunGreed"]			 = make_shared<GunGreed>();
	//_scenes["Collision"]			 = make_shared<CollisionScene>();
	//_scenes["AvoidDDong"]			 = make_shared<AvoidDDong>();
	//_scenes["Sprite"]				 = make_shared<SpriteScene>();
	//_scenes["CupHead"]				 = make_shared<CupHeadScene>();
	//_scenes["Filter"]				 = make_shared<FilterScene>();
	_scenes["Effect"]				 = make_shared<EffectScene>();
	_curScene = _scenes["Effect"];
}

Program::~Program()
{
}

void Program::Update()
{
	if (KEY_DOWN(VK_F1))
	{
		Collider::_isDebug = !Collider::_isDebug;
	}

	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();

	_curScene->Update();

	Camera::GetInstance()->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	// imgui
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Camera::GetInstance()->SetProjectionBuffer(WIN_WIDTH, WIN_HEIGHT);
	Camera::GetInstance()->SetCameraWorldBuffer();

	_curScene->PreRender();

	Camera::GetInstance()->SetViewPort();
	AlphaBlendState->SetState();

	// Scene Render
	_curScene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	Camera::GetInstance()->PostRender();
	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
