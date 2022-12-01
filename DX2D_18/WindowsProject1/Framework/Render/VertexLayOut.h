#pragma once


struct Vertex_Bagic
{
    XMFLOAT3 pos;
};

struct Vertex_Color
{
    XMFLOAT3 pos;
    XMFLOAT4 color;
};

struct Vertex_UV
{
    XMFLOAT3 pos;
    XMFLOAT2 uv; // 텍스쳐 좌표
};
