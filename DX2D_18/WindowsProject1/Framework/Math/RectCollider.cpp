#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	_type = ColliderType::RECT;
	CreateVertices();
}

RectCollider::RectCollider(Vector2 size)
: _size(size)
{
	_type = ColliderType::RECT;
	CreateVertices();
}

RectCollider::~RectCollider()
{
}

bool RectCollider::IsCollision(Vector2 pos)
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return false;
}

Vector2 RectCollider::LeftTop()
{
	return Vector2(0, 0);
}

Vector2 RectCollider::RightBottom()
{
	return Vector2(0, 0);
}

void RectCollider::CreateVertices()
{
	Vector2 halfSize = _size * 0.5f;

	// 왼쪽 위
	_vertices.emplace_back(-halfSize._x, halfSize._y);
	// 오른쪽 위
	_vertices.emplace_back(halfSize._x, halfSize._y);
	// 오른쪽 아래
	_vertices.emplace_back(halfSize._x, -halfSize._y);
	// 왼쪽 아래
	_vertices.emplace_back(-halfSize._x, -halfSize._y);
	// 왼쪽 위
	_vertices.emplace_back(-halfSize._x, halfSize._y);

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,1.0f,0.0f,1.0f };
}
