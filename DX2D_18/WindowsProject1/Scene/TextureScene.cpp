#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_texture1 = make_shared<Texture>(L"2B.png");
	_texture2 = make_shared<Texture>(L"BattleMaster.png");
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
