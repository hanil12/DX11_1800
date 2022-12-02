#include "framework.h"
#include "Texture.h"

Texture::Texture(wstring file)
{
	wstring path = L"Resource/Texture/" + file;
	_srv = make_shared<SRV>(path);
	_sampler = make_shared<SamplerState>();

	_size = _srv->GetSize();

	CreateVertricesAndIndices();
	_vBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_UV), _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

	_vs = make_shared<VertexShader>(L"Shaders/Tutorial.hlsl");
	_ps = make_shared<PixelShader>(L"Shaders/Tutorial.hlsl");

}

Texture::~Texture()
{
}

void Texture::Update()
{
}

void Texture::Render()
{
	_vBuffer->IASet(0);
	_indexBuffer->IASet();

	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv->Set(0);
	_sampler->Set(0);

	_vs->Set();
	_ps->Set();

	DC->DrawIndexed(_indices.size(), 0, 0);
}

void Texture::CreateVertricesAndIndices()
{
	Vertex_UV v;
	float widthRate = (_size._x / WIN_WIDTH);
	float heightRate = (_size._y / WIN_HEIGHT);
	v.pos = { -widthRate, heightRate, 0.0f }; // 왼쪽 위
	v.uv = { 0.0f, 0.0f };
	_vertices.push_back(v);

	v.pos = { widthRate, -heightRate, 0.0f }; // 오른쪽 아래
	v.uv = { 1.0f,1.0f };
	_vertices.push_back(v);

	v.pos = { -widthRate, -heightRate, 0.0f }; // 왼쪽 아래
	v.uv = { 0.0f, 1.0f };
	_vertices.push_back(v);

	v.pos = { widthRate, heightRate, 0.0f }; // 오른쪽 위
	v.uv = { 1.0f, 0.0f };
	_vertices.push_back(v);


	_indices.push_back(0);
	_indices.push_back(1);
	_indices.push_back(2);

	_indices.push_back(0);
	_indices.push_back(3);
	_indices.push_back(1);
}
