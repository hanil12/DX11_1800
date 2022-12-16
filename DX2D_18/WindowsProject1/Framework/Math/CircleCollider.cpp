#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	_type = ColliderType::CIRCLE;
	CreateVertices();
}

CircleCollider::CircleCollider(float radius)
: _radius(radius)
{
	_type = ColliderType::CIRCLE;
	CreateVertices();
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

void CircleCollider::CreateVertices()
{
	UINT vertexCount = 36;

	for (int i = 0; i < 37; i++)
	{
		Vertex_Bagic vertex;
		vertex.pos.x = _radius * cos((2 * PI * i) / 36);
		vertex.pos.y = _radius * sin((2 * PI * i) / 36);
		_vertices.push_back(vertex);
	}

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,1.0f,0.0f,1.0f };

}
