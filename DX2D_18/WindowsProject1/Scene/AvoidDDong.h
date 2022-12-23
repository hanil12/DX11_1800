#pragma once
class AvoidDDong : public Scene
{
public:
	AvoidDDong();
	virtual ~AvoidDDong();

	virtual void PreRender() override;
	virtual void Update() override;
	virtual void Render() override;
private:
	float _check = 0.0f;
	float _delay = 1.0f;

	shared_ptr<AD_BackGround> _bg;
	shared_ptr<AvoidPlayer> _player;
	vector<shared_ptr<DDong>> _ddongs;
	shared_ptr<DDong> _ddong;
};

