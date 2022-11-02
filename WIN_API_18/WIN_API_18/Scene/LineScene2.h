#pragma once
class LineScene2 : public Scene
{
public:
	LineScene2();
	virtual ~LineScene2();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Line> _line1; // 고정
	shared_ptr<Line> _line2; // 움직임
	shared_ptr<Line> _line3; // line1에대한 line2의 그림자(투영, projection)
};

