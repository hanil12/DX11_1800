#pragma once
class GunGreed : public Scene
{
public:
	GunGreed();
	virtual ~GunGreed();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Quad> _player;
	shared_ptr<Quad> _player2;
	shared_ptr<Quad> _gun;
};

