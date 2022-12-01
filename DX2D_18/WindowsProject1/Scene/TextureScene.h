#pragma once
class TextureScene : public Scene
{
public:
	TextureScene();
	virtual ~TextureScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SamplerState> _sampler;
	shared_ptr<SRV> _srv;
};

