#pragma once
class Cup_Player
{
public:
	enum State // State ����
	{
		IDLE = 0,
		RUN = 1,
		SHOT = 2,
		JUMP = 3
	};

	Cup_Player();
	~Cup_Player();

	void Init();
	void Input();
	void Jump();
	void Shot();
	void SetIdle();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);

	void SetText() { _text = "IDLE END!!!"; }

	void SetLeft();
	void SetRight();

	shared_ptr<Transform> GetTransform() { return _transform; }
	shared_ptr<Collider> GetCollider() { return _collider; }

private:
	State _state = State::IDLE;

	vector<shared_ptr<Cup_Bullet>> _bullets;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _firePos;
	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector<shared_ptr<Action>> _actions;

	float _speed = 300.0f;

	float _jumpPower = 0.0f;

	string _text = "Hello World!!!";
};

