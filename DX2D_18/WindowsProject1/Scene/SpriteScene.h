#pragma once
class SpriteScene : public Scene
{
public:
	SpriteScene();
	virtual ~SpriteScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<Quad> _quad;
	shared_ptr<SpriteBuffer> _maxFrameBuffer;
	// _quad의 ps 바꾸기
	// maxFrameBuffer 적용하기
};

