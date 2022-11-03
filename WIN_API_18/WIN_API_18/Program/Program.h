#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render(HDC hdc);

	static HDC _backBuffer;

private:
	shared_ptr<Scene> _targetScene;
	unordered_map<string, shared_ptr<Scene>> _scenes;

	// BackBuffer
	// Buffer -> Texture(픽셀의 모음)를 임시적으로 저장하는 공간
	HBITMAP _hBit;
};

