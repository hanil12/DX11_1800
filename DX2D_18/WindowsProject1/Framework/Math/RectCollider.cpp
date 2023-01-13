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
	Vector2 leftTop = this->LeftTop();
	Vector2 rightBottom = this->RightBottom();

	if (pos.x > leftTop.x && pos.x < rightBottom.x)
	{
		if (pos.y < leftTop.y && pos.y > rightBottom.y)
		{
			return true;
		}
	}
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	float left = LeftTop().x;
	float right = RightBottom().x;
	float top = LeftTop().y;
	float bottom = RightBottom().y;

	Vector2 center = circle->GetTransform()->GetWorldPos();
	float radius = circle->GetWorldRadius();

	if (center.x > left - radius && center.x < right + radius
		&& center.y < top + radius && center.y > bottom - radius)
		return true;

	if (circle->IsCollision(LeftTop()) || circle->IsCollision(RightBottom())
		|| circle->IsCollision(Vector2(left, bottom)) || circle->IsCollision(Vector2(right, top)))
		return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	Vector2 leftTop = other->LeftTop();
	Vector2 rightBottom = other->RightBottom();
	if (this->IsCollision(leftTop))
	{
		return true;
	}
	if (this->IsCollision(rightBottom))
	{
		return true;
	}
	if (this->IsCollision(Vector2(leftTop.x, rightBottom.y)) == true)
	{
		return true;
	}
	if (this->IsCollision(Vector2(rightBottom.x, leftTop.y)) == true)
	{
		return true;
	}
	return false;
}

bool RectCollider::IsCollision_OBB(shared_ptr<CircleCollider> circle)
{
	OBB_Info rect1 = GetObb();

	Vector2 centerToCenter = circle->GetTransform()->GetWorldPos() - rect1.position;

	Vector2 nea1 = rect1.direction[0];
	Vector2 ea1 = nea1 * rect1.length[0];
	Vector2 nea2 = rect1.direction[1];
	Vector2 ea2 = nea2 * rect1.length[1];

	{
		float lengthA = circle->GetWorldRadius();
		float lengthB = SeparateAxis(centerToCenter.Normal(), ea1, ea2);
		float distance = centerToCenter.Length();
		if (distance > lengthA + lengthB)
		{
			Vector2 point1 = rect1.position - ea1 - ea2;
			Vector2 point2 = rect1.position + ea1 - ea2;
			Vector2 point3 = rect1.position - ea1 + ea2;
			Vector2 point4 = rect1.position + ea1 + ea2;

			if (circle->IsCollision(point1) ||
				circle->IsCollision(point2) ||
				circle->IsCollision(point3) ||
				circle->IsCollision(point4))
				return true;

			return false;
		}
	}

	{
		float centerProjection = abs(centerToCenter.Dot(nea1));
		float lengthA = ea1.Length();
		float lengthB = circle->GetWorldRadius();
		if (centerProjection > lengthA + lengthB)
			return false;
	}

	{
		float centerProjection = abs(centerToCenter.Dot(nea2));
		float lengthA = ea2.Length();
		float lengthB = circle->GetWorldRadius();
		if (centerProjection > lengthA + lengthB)
			return false;
	}

	return true;
}

bool RectCollider::IsCollision_OBB(shared_ptr<RectCollider> other)
{
	OBB_Info rect1 = GetObb();
	OBB_Info rect2 = other->GetObb();

	Vector2 centerToCenter = rect2.position - rect1.position;

	Vector2 nea1 = rect1.direction[0];
	Vector2 ea1 = nea1 * rect1.length[0];
	Vector2 nea2 = rect1.direction[1];
	Vector2 ea2 = nea2 * rect1.length[1];

	Vector2 neb1 = rect2.direction[0];
	Vector2 eb1 = neb1 * rect2.length[0];
	Vector2 neb2 = rect2.direction[1];
	Vector2 eb2 = neb2 * rect2.length[1];

	{
		float centerProjection = abs(centerToCenter.Dot(nea1));
		float lengthA = ea1.Length();
		float lengthB = SeparateAxis(nea1, eb1, eb2);
		if (centerProjection > lengthA + lengthB)
			return false;
	}

	{
		float centerProjection = abs(centerToCenter.Dot(nea2));
		float lengthA = ea2.Length();
		float lengthB = SeparateAxis(nea2, eb1, eb2);
		if (centerProjection > lengthA + lengthB)
			return false;
	}

	{
		float centerProjection = abs(centerToCenter.Dot(neb1));
		float lengthB = eb1.Length();
		float lengthA = SeparateAxis(neb1, ea1, ea2);
		if (centerProjection > lengthA + lengthB)
			return false;
	}

	{
		float centerProjection = abs(centerToCenter.Dot(neb2));
		float lengthB = eb2.Length();
		float lengthA = SeparateAxis(neb2, ea1, ea2);
		if (centerProjection > lengthA + lengthB)
			return false;
	}

	return true;
}


Vector2 RectCollider::LeftTop()
{
	Vector2 result;
	Vector2 half = GetWorldSize() * 0.5f;

	result.x = _transform->GetWorldPos().x - half.x;
	result.y = _transform->GetWorldPos().y + half.y;

	return result;
}

Vector2 RectCollider::RightBottom()
{
	Vector2 result;
	Vector2 half = GetWorldSize() * 0.5f;
	result.x = _transform->GetWorldPos().x + half.x;
	result.y = _transform->GetWorldPos().y - half.y;

	return result;
}

RectCollider::OBB_Info RectCollider::GetObb()
{
	OBB_Info info;

	info.position = _transform->GetWorldPos();

	info.length[0] = GetWorldSize().x * 0.5f;
	info.length[1] = GetWorldSize().y * 0.5f;

	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, *_transform->GetMatrix());

	info.direction[0] = { matrix._11, matrix._12 };
	info.direction[1] = { matrix._21, matrix._22 };

	info.direction[0].Normallize();
	info.direction[1].Normallize();

	return info;
}

Vector2 RectCollider::GetWorldSize()
{
	Vector2 result;

	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, *_transform->GetMatrix());

	result.x = _size.x * matrix._11;
	result.y = _size.y * matrix._22;

	return result;
}

float RectCollider::SeparateAxis(Vector2 separate, Vector2 e1, Vector2 e2)
{
	float r1 = abs(separate.Dot(e1));
	float r2 = abs(separate.Dot(e2));

	return r1 + r2;
}

void RectCollider::CreateVertices()
{
	Vector2 halfSize = _size * 0.5f;

	_vertices.emplace_back(-halfSize.x, halfSize.y);
	_vertices.emplace_back(halfSize.x, halfSize.y);
	_vertices.emplace_back(halfSize.x, -halfSize.y);
	_vertices.emplace_back(-halfSize.x, -halfSize.y);
	_vertices.emplace_back(-halfSize.x, halfSize.y);

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,255.0f,0.0f,1.0f };
}
