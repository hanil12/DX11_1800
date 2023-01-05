#include "framework.h"
#include "Effect.h"

Effect::Effect(wstring file,Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
{
	_sprite = make_shared<Sprite>(file, maxFrame, size);

	CreateAction(file, maxFrame, speed, type);
}

Effect::~Effect()
{
}

void Effect::Update()
{
}

void Effect::Render()
{
}

void Effect::PostRender()
{
}

void Effect::CreateAction(wstring file, Vector2 maxFrame, float speed, Action::Type type)
{
	vector<Action::Clip> clips;

	float w = _sprite->GetImage().x / maxFrame.x;
	float h = _sprite->GetImage().y / maxFrame.y;

	for (int y = 0; y < maxFrame.y; y++)
	{
		for (int x = 0; x < maxFrame.x; x++)
		{
			Action::Clip clip = Action::Clip(x, y, w, h, SRVManager::GetInstance()->AddSRV(file));
			clips.push_back(clip);
		}
	}

	string effectName(file.begin(), file.end());
	//Resource/Texture/Effects/explosion.png
	//effectName.substr()

	_action = make_shared<Action>(clips, effectName, type, speed);
}

void Effect::Play(Vector2 pos)
{
}
