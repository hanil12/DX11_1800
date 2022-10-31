#pragma once
class FortrissScene : public Scene
{
public:
	FortrissScene();
	virtual ~FortrissScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Cannon> _cannon;
};

