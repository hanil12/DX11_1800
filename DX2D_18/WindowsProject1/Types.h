#pragma once

#define RED		 RGB(255,0,0)
#define GREEN	 RGB(0,255,0)
#define BLUE	 RGB(0,0,255)

#define WIN_WIDTH		 1280
#define WIN_HEIGHT		 720
#define CENTER_X		 640
#define CENTER_Y		 360

#define PI				 3.141592
#define GRAVITY			 30

#define DEVICE Device::GetInstance()->GetDevice()
#define DC Device::GetInstance()->GetDeviceContext()

#define KEY_DOWN(k) Keyboard::GetInstance()->Down(k)
#define KEY_UP(k) Keyboard::GetInstance()->Up(k)
#define KEY_PRESS(k) Keyboard::GetInstance()->Press(k)

#define DELTA_TIME Timer::GetInstance()->GetElasedTime()
#define RUN_TIME Timer::GetInstance()->GetRunTime();

#define SAMPLER StateManager::GetInstance()->GetSampler()
#define AlphaBlendState StateManager::GetInstance()->GetAlphaBlend()
#define AdditiveBlendState StateManager::GetInstance()->GetAdditiveBlend()

#define ADD_VS(k) ShaderManager::GetInstance()->AddVS(k)
#define ADD_PS(k) ShaderManager::GetInstance()->AddPS(k)

#define CAMERA Camera::GetInstance()

#define EFFECT EffectManager::GetInstance()

#define SOUND Audio::GetInstance()

#define SCENE SceneManager::GetInstance()

#define MOUSE_POS CAMERA->GetWorldMousePos()

#define LERP(s,e,t) s + (e - s) * t

using Float2 = XMFLOAT2;

using CallBack = std::function<void()>;
using CallBack_1 = std::function<void(int)>;

enum ItemType
{
	NONE,
	WEAPON,
	ARMOR,
	POTION
};

struct ItemData
{
	string name = "";
	UINT price = 0;
	UINT endurance = 0;
	UINT health = 0;
	UINT attack = 0;
	UINT frameX = 10;
	UINT frameY = 4;
};