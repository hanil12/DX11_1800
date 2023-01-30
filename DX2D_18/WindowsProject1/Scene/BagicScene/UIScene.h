#pragma once
class UIScene : public Scene
{
public:
	UIScene();
	virtual ~UIScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<HPBar> _bar;
};

