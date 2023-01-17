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

	// 윈도우 핸들
	HWND _hWnd;

	// 외주를 맡기고 실질적인 공사 대표 뽑기
	// 컴퓨터의 하드웨어 기능 점검, 리소스 할당
	// -> 인력사무소장
	Microsoft::WRL::ComPtr<ID3D11Device>               _device;
	// 세트장을 실질적으로 꾸며주는 연출가
	// 렌더링 대상 결정
	// -> 리소스를 그래픽 파이프라인에 바인딩, GPU가 수행할 명령 지시
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>      _deviceContext;
	// DX의 인터페이스로써 1개 이상의 표면을 포함할 수 있다.
	// 각각의 표면(버퍼, 텍스쳐)를 출력하기 전에 데이터를 보관한다.
	Microsoft::WRL::ComPtr<IDXGISwapChain>           _swapChain;
	// 후면 버퍼를 가리키는 포인터
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView;
};

