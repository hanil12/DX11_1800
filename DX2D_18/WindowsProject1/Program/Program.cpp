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

Program::Program()
{
	srand(static_cast<UINT>(time(nullptr)));

	//_scenes["TextureScene"]		 = make_shared<TextureScene>();
	//_scenes["PlanetScene"]		 = make_shared<PlanetScene>();
	//_scenes["GunGreed"]			 = make_shared<GunGreed>();
	//_scenes["Collision"]			 = make_shared<CollisionScene>();
	//_scenes["AvoidDDong"]			 = make_shared<AvoidDDong>();
	_scenes["Sprite"]				 = make_shared<SpriteScene>();
	_scenes["CupHead"]				 = make_shared<CupHeadScene>();
	_scenes["Filter"]				 = make_shared<FilterScene>();
	_curScene = _scenes["Filter"];

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
	if (KEY_DOWN(VK_F1))
	{
		Collider::_isDebug = !Collider::_isDebug;
	}

	// Scene Update();
	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();

	_curScene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	// imgui
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	AlphaBlendState->SetState();

	_curScene->PreRender();

	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);

	// Scene Render
	_curScene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
