#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render();

private:
	unordered_map<string, shared_ptr<Scene>> _scenes;
	shared_ptr<Scene> _curScene;
};

