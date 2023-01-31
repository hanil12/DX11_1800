Texture2D map :register(t0);
SamplerState samp : register(s0);

// 상수버퍼
cbuffer LeftRight : register(b0)
{
	int leftRight;
	int padding[3];
}

// VertexBuffer -> InputLayOut(입력조립기단계) -> VertexShader -> PixelShader
struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;

	float2 maxFrame : MAXFRAME;
	float2 curFrame : CURFRAME;
};

// SV_TARGET -> 그릴 곳... 우리한테는 후면버퍼(RTV)
float4 PS(PixelInput input) : SV_TARGET
{
	float2 spriteUV;
	spriteUV.x = input.uv.x / input.maxFrame.x + input.curFrame.x / input.maxFrame.x;
	spriteUV.y = input.uv.y / input.maxFrame.y + input.curFrame.y / input.maxFrame.y;

	float4 result = map.Sample(samp, spriteUV);

	return result;
}