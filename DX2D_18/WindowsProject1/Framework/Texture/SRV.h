#pragma once
class SRV
{
public:
	SRV(wstring file);
	~SRV();

	void Set(int slot);
private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> _shaderResourceView;
};

