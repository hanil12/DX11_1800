#pragma once
class DDong
{
public:
	DDong();
	~DDong();

	void Update();
	void Render();

	void Init();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Collider> GetCollider() { return _circleCol; }
	bool IsCollisionWithPlayer(shared_ptr<AvoidPlayer> player);

	bool _isActive = true;
private:
	float _speed = 280.0f;

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _circleCol;
};

