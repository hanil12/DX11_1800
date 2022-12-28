#pragma once
class Cup_Player
{
public:
	enum State // State ∆–≈œ
	{
		IDLE
	};

	Cup_Player();
	~Cup_Player();

	void Input();

	void Update();
	void Render();
	void PostRender();

	void CreateAction();

	void SetText() { _text = "IDLE END!!!"; }

private:
	State _state;

	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	float _speed = 30.0f;
	string _text = "Hello World!!!";
};

