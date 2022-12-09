Texture2D map :register(t0);
SamplerState samp : register(s0);

struct VertexInput
{
	float4 pos : POSITION;
	float2 uv : UV;
};

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// VertexShader
PixelInput VS(VertexInput input)
{
	PixelInput result;
	result.pos = input.pos;
	result.uv = input.uv;

	return result;
}

// SV_TARGET -> �׸� ��... �츮���״� �ĸ����(RTV)
float4 PS(PixelInput input) : SV_TARGET
{
	float4 result = map.Sample(samp, input.uv);

	return result;
}