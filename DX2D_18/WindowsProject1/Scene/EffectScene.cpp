#include "framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
	CAMERA->SetTarget(nullptr);

	_effect = make_shared<Effect>
		(L"Resource/Texture/Effects/explosion.png", Vector2(5, 3), Vector2(100, 100));
}

EffectScene::~EffectScene()
{
}

void EffectScene::Update()
{
}

void EffectScene::Render()
{
}
