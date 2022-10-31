#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void MoveLeft();
	void MoveRight();

	shared_ptr<CircleCollider> GetBody() { return _body; }
	float& GetAngle() { return _angle; }

	bool _isActive = true;

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<Barrel> _barrel;

	float _speed = 2.0f;
	float _angle = 0.0f;
	float _barrelSize = 60.0f;

	// shared_ptr<Bullet> _ bullet;
};

