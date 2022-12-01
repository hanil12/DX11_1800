#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_vs = make_shared<VertexShader>(L"Shaders/Tutorial.hlsl");
	_ps = make_shared<PixelShader>(L"Shaders/Tutorial.hlsl");

	_vBuffer = make_shared<VertexBuffer>();
	_srv = make_shared<SRV>(L"Resource/2B.png");
	_sampler = make_shared<SamplerState>();
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
}

void TextureScene::Render()
{
	_vBuffer->Set(0);

	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv->Set(0);
	_sampler->Set(0);

	_vs->Set();
	_ps->Set();

	DC->Draw(6, 0);
}
