#include "framework.h"
#include "Planet.h"

Planet::Planet(string name, Vector2 size)
{
	wstring path;
	path.assign(name.begin(), name.end());
	_texture = make_shared<Texture>(path, size);
}

Planet::~Planet()
{
}

void Planet::Update()
{
	_texture->Update();
}

void Planet::Render()
{
	_texture->Render();
}

void Planet::SetParent(shared_ptr<Transform>& parent)
{
	_texture->SetParent(parent);
}
