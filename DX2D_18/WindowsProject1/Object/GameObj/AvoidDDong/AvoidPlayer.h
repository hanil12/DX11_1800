#pragma once
class AvoidPlayer
{
public:
	AvoidPlayer();
	~AvoidPlayer();

	UINT& GetHP() { return _hp; }

	void Update();
	void Render();

	void SetLeftRight(Vector2 leftRight) { _leftRight = leftRight; }

	shared_ptr<Collider> GetCollider() { return _rectCol; }

	bool _isActive = true;
private:
	void Input();

	UINT _hp = 10;
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;

	Vector2 _leftRight = { 0, WIN_WIDTH };

	float _speed = 300.0f;
};

