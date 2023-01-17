#pragma once
class Device
{
private:
	Device(HWND hWnd);
	~Device();

	void CreateDeviceAndSwapChain();
	void CreateDoubleBuffer();

public:
	static void Create(HWND hWnd)
	{
		if (_instance == nullptr)
			_instance = new Device(hWnd);
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Device* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		return nullptr;
	}

	Microsoft::WRL::ComPtr<ID3D11Device> GetDevice() { return _device; }
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetDeviceContext() { return _deviceContext; }
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> GetRTV() { return _renderTargetView; }
	Microsoft::WRL::ComPtr< IDXGISwapChain> SwapChain() { return _swapChain; }

	void Clear();
	void Present();

private:
	static Device* _instance;

	// ������ �ڵ�
	HWND _hWnd;

	// ���ָ� �ñ�� �������� ���� ��ǥ �̱�
	// ��ǻ���� �ϵ���� ��� ����, ���ҽ� �Ҵ�
	// -> �η»繫����
	Microsoft::WRL::ComPtr<ID3D11Device>               _device;
	// ��Ʈ���� ���������� �ٸ��ִ� ���Ⱑ
	// ������ ��� ����
	// -> ���ҽ��� �׷��� ���������ο� ���ε�, GPU�� ������ ��� ����
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>      _deviceContext;
	// DX�� �������̽��ν� 1�� �̻��� ǥ���� ������ �� �ִ�.
	// ������ ǥ��(����, �ؽ���)�� ����ϱ� ���� �����͸� �����Ѵ�.
	Microsoft::WRL::ComPtr<IDXGISwapChain>           _swapChain;
	// �ĸ� ���۸� ����Ű�� ������
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView;
};

