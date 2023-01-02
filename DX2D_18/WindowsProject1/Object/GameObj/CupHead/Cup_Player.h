#pragma once
class Cup_Player
{
public:
	enum State // State ∆–≈œ
	{
		IDLE = 0,
		RUN = 1,
		FIRE = 2
	};

	Cup_Player();
	~Cup_Player();

	void Input();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string state);

	void SetText() { _text = "IDLE END!!!"; }

	void SetLeft();
	void SetRight();

private:
	State _state = State::IDLE;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector<shared_ptr<Action>> _actions;

	float _speed = 30.0f;
	string _text = "Hello World!!!";
};

