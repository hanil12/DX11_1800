#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_texture1 = make_shared<Texture>(L"2B.png", Vector2(50,50));
	_texture2 = make_shared<Texture>(L"BattleMaster.png", Vector2 (30,30));
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	_texture1->Update();
	_texture2->Update();
}

void TextureScene::Render()
{
	_texture1->Render();
	_texture2->Render();
}
