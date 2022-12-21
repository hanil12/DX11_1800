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
		_srtMatrix *= *(_parent->GetMatrix());
	}

	_worldBuffer->SetData(_srtMatrix);
	_worldBuffer->Update();
}

void Transform::SetWorldBuffer()
{
	_worldBuffer->SetVSBuffer(0);
}

Vector2& Transform::GetScale()
{
	return _scale;
}

Vector2 Transform::GetWorldScale()
{
	if (_parent == nullptr)
		return _scale;
	return _scale;
}

Vector2 Transform::GetWorldPos()
{
	if (_parent != nullptr)
	{
		XMFLOAT4X4 matrix;
		XMStoreFloat4x4(&matrix, _srtMatrix);
		Vector2 result;
		result._x = matrix._41;
		result._y = matrix._42;

		return result;
	}
	return _pos;
}

float& Transform::GetAngle()
{
	return _angle;
}

float Transform::GetWorldAngle()
{
	if (_parent != nullptr)
		return _angle + _parent->GetAngle();
	return _angle;
}
