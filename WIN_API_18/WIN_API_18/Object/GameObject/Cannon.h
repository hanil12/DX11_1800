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
	void Fire();

	shared_ptr<CircleCollider> GetBody() { return _body; }
	const float& GetAngle() { return _angle; }
	void SetAngle(float angle) { _angle = angle; }

	bool IsCollision(shared_ptr<Bullet> bullet);
	vector<shared_ptr<Bullet>> GetBullets() { return _bullets; }

	bool _isActive = true;

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<Barrel> _barrel;
	// ���ʿ� �޸�Ǯ ��´�.
	vector<shared_ptr<Bullet>> _bullets;

	UINT _poolCount = 30;
	float _speed = 2.0f;
	float _angle = 0.0f;
	float _barrelSize = 60.0f;

	// shared_ptr<Bullet> _ bullet;
};

