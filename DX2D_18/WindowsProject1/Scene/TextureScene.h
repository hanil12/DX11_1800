#pragma once
class TextureScene : public Scene
{
public:
	TextureScene();
	virtual ~TextureScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<Texture> _texture1;
	shared_ptr<Texture> _texture2;
};

