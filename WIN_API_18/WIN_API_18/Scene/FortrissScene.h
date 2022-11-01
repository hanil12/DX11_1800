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
	shared_ptr<Cannon> _cannon2;
	float _angle = 0.0f;
};

