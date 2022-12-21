#pragma once
class GunGreed : public Scene
{
public:
	GunGreed();
	virtual ~GunGreed();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Player> _player;
	shared_ptr<RectCollider> _target;
};
