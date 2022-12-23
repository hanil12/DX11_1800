#pragma once
class AD_BackGround
{
public:
	AD_BackGround();
	~AD_BackGround();

	Vector2 LeftRight();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _quad;
};

