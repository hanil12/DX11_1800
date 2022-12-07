#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_worldBuffer = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::Update()
{
	XMMATRIX S = XMMatrixScaling(_scale._x, _scale._y, 1);
	XMMATRIX R = XMMatrixRotationZ(_angle);
	XMMATRIX T = XMMatrixTranslation(_pos._x, _pos._y, 0);

	_srtMatrix = S * R * T;

	if (_parent != nullptr)
	{
		_srtMatrix *= (*_parent);
	}

	_worldBuffer->SetData(_srtMatrix);
	_worldBuffer->Update();
}

void Transform::SetWorldBuffer()
{
	_worldBuffer->SetVSBuffer(0);
}
