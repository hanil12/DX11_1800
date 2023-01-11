#pragma once
class Cup_Bullet
{
public:
	Cup_Bullet();
	~Cup_Bullet();

	void CreateAction();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }

	void SetDirection(Vector2 dir);

	void SetTarget(shared_ptr<Collider> other);
	bool IsCollision();

	bool isActive = false;
private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	weak_ptr<Collider> _target;

	Vector2 _direction = { 0,0 };
	float _speed = 500.0f;
};

