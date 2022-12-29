
cbuffer Frame : register(b1)
{
	float2 startPos;
	float2 imageSize;
	float2 size;
	float2 padding0;
}

cbuffer LeftRight : register(b0)
{
	int leftRight;
	int padding1[3];
}

Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// SV_TARGET -> 그릴 곳... 우리한테는 후면버퍼(RTV)
float4 PS(PixelInput input) : SV_TARGET
{
	float2 spriteUV;
	spriteUV.x = input.uv.x * (size.x / imageSize.x) + (startPos.x / imageSize.x);
	spriteUV.y = input.uv.y * (size.y / imageSize.y) + (startPos.y / imageSize.y);

	float4 result = map.Sample(samp, spriteUV);

	return result;
}