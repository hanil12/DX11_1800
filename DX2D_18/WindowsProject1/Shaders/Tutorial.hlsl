
// VertexShader
float4 VS(float4 pos : POSITION) : SV_POSITION
{
	return pos;
}

// SV_TARGET -> 그릴 곳... 우리한테는 후면버퍼(RTV)
float4 PS() : SV_TARGET
{
	return float4(1.0f,0.7f,0.0f,1.0f);
}