#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	CreateVertices();
	CreateVertexBuffer();
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::Set(int slot)
{
    DC->IASetVertexBuffers(slot, 1, vertexBuffer.GetAddressOf(), &_stride, &_offset);
}

void VertexBuffer::CreateVertices()
{
    Vertex_UV v;
    v.pos = { -0.5f, 0.5f, 0.0f }; // 왼쪽 위
    v.uv = { 1.0f, 1.0f };
    _vertices.push_back(v);

    v.pos = { 0.5f, -0.5f, 0.0f }; // 오른쪽 아래
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { -0.5f, -0.5f, 0.0f }; // 왼쪽 아래
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { 0.5f, 0.5f, 0.0f }; // 오른쪽 위
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);

    v.pos = { 0.5f, -0.5f, 0.0f }; // 오른쪽 아래
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { -0.5f, 0.5f, 0.0f }; // 왼쪽 위
    v.uv = { 1.0f, 1.0f };
    _vertices.push_back(v);

    _stride = sizeof(Vertex_UV);
    _offset = 0;
}

void VertexBuffer::CreateVertexBuffer()
{
    // Vertex 버퍼 : Vertex
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = _stride * _vertices.size();
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = _vertices.data();

    DEVICE->CreateBuffer(&bd, &initData, vertexBuffer.GetAddressOf());
}
