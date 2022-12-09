#pragma once
class Texture
{
public:
	Texture(wstring file);
	Texture(wstring file, Vector2 size);
	~Texture();

	void Update();
	void Render();

	void SetParent(shared_ptr<Transform> parent) { _transform->SetParent(parent); }

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	void CreateVertricesAndIndices();
	vector<Vertex_UV> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;

	Vector2 _size = { 1.0f,1.0f };

	// 오브젝트를 월드에서 움직이기 위한 Matrix
	// -> 컴포넌트 패턴(부품처럼 붙이는 형식)
	// => 유니티
	shared_ptr<Transform> _transform;
};

