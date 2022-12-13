#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }

	void SetDir(const Vector2& dir) { _dir = dir.Normallize(); }

	bool _isActive = false;
private:
	shared_ptr<Quad> _quad;

	float		_speed = 50.0f;
	Vector2		_dir = Vector2();
};

