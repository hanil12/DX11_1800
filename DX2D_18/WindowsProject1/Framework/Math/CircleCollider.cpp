#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	_type = ColliderType::CIRCLE;
}

CircleCollider::CircleCollider(float radius)
: _radius(radius)
{
	_type = ColliderType::CIRCLE;
}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::IsCollision(Vector2 pos)
{

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	return false;
}
