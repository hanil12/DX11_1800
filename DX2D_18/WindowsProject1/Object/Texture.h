#pragma once
class Texture
{
public:
	Texture(wstring file);
	Texture(wstring file, Vector2 size);
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

	Vector2 _size = { 1.0f,1.0f };

	Vector2 _scale = { 1.0f,1.0f };
	float _angle = 0.0f;
	Vector2 _pos = { 0.0f,0.0f };

	XMMATRIX _srtMatrix = XMMatrixIdentity();
	shared_ptr<MatrixBuffer> _worldBuffer;

	XMMATRIX* _parent = nullptr;
};

