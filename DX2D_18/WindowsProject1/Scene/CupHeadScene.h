#pragma once
class CupHeadScene : public Scene
{
public:
	CupHeadScene();
	virtual ~CupHeadScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
private:
	shared_ptr<Cup_Player> _player;
	shared_ptr<Cup_Background> _bg;
};

