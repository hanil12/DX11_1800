#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render(HDC hdc);

private:
	shared_ptr<Scene> _targetScene;
	unordered_map<string, shared_ptr<Scene>> _scenes;
};

