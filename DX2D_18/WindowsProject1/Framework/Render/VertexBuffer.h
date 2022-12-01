#pragma once
class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void Set(int slot);

private:
	void CreateVertices();
	void CreateVertexBuffer();

	vector<Vertex_UV> _vertices;
	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;

	UINT _stride;
	UINT _offset;
};

