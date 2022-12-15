#pragma once
class RectCollider : public Collider
{
public:
	RectCollider();
	RectCollider(Vector2 size);
	virtual ~RectCollider();

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;

	Vector2 LeftTop();
	Vector2 RightBottom();
	
	const Vector2& GetSize() { return _size; }

private:
	void CreateVertices();
	Vector2 _size = Vector2();
};

