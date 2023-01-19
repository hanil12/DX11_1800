#pragma once
class Cup_Boss
{
public:
	Cup_Boss();
	~Cup_Boss();

	void CreateAction();

	void Init();
	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

	void CreateBullets();

	void Fire(shared_ptr<Cup_Player> player);
	void Attack(shared_ptr<Cup_Player> player);

	void SetPlayer(shared_ptr<Cup_Player> player) { _player = player; }
	void Fire();

private:
	vector<shared_ptr<Cup_Bullet>> _bullets; // ГЊСп
	shared_ptr<Transform> _firePos;

	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	weak_ptr<Cup_Player> _player;

	const float _fireDelay = 1.5f;
	float _fireCheck = 0.0f;
};

