#pragma once

#define WIN_WIDTH		 1980
#define WIN_HEIGHT		 1080
#define CENTER_X		 640
#define CENTER_Y		 360

#define PI				 3.141592

#define DEVICE Device::GetInstance()->GetDevice()
#define DC Device::GetInstance()->GetDeviceContext()

#define KEY_DOWN(k) Keyboard::GetInstance()->Down(k)
#define KEY_UP(k) Keyboard::GetInstance()->Up(k)
#define KEY_PRESS(k) Keyboard::GetInstance()->Press(k)

#define DELTA_TIME Timer::GetInstance()->GetElasedTime()

#define SAMPLER StateManager::GetInstance()->GetSampler()
#define AlphaBlendState StateManager::GetInstance()->GetAlphaBlend()
#define AdditiveBlendState StateManager::GetInstance()->GetAdditiveBlend()

