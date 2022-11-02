#pragma once
class Arkanoid : public Scene
{
public:
	Arkanoid();
	virtual ~Arkanoid();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Map> _map;
};

