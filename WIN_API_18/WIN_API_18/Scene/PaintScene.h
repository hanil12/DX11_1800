#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	virtual ~PaintScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
private:
	HBRUSH	_brushes[3];
	HPEN	_pens[3];

	shared_ptr<RectCollider> _rect1;
	shared_ptr<RectCollider> _rect2;
	shared_ptr<CircleCollider> _circle1;
	shared_ptr<CircleCollider> _circle2;
	shared_ptr<CircleCollider> _circle3;
};

