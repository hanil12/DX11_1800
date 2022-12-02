#pragma once
class Texture
{
public:
	Texture(wstring file);
	~Texture();

	void Update();
	void Render();

private:
	void CreateVertricesAndIndices();
	vector<Vertex_UV> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SamplerState> _sampler;
	shared_ptr<SRV> _srv;

	Vector2 _size;
};

