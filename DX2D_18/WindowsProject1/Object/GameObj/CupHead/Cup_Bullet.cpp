#include "framework.h"
#include "Cup_Bullet.h"

Cup_Bullet::Cup_Bullet()
{
	CreateAction();

	_collider = make_shared<CircleCollider>(15);
	_collider->GetTransform()->SetParent(_sprite->GetTransform());
	_collider->GetTransform()->GetPos().y += 30;
}

Cup_Bullet::~Cup_Bullet()
{
}

void Cup_Bullet::CreateAction()
{
	wstring srvPath;
	srvPath = L"CupHead/Bullet/Special_Bullet_Loop.png";
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(srvPath);
	vector<Action::Clip> clips;

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string xmlPath = "Resource/Texture/CupHead/Bullet/Special_Bullet_Loop.xml";
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	int averageW = 0;
	int averageH = 0;
	int count = 0;

	while (true)
	{
		if (row == nullptr)
			break;
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		averageW += w;
		int h = row->FindAttribute("h")->IntValue();
		averageH += h;

		count++;

		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	averageW /= count * 4.5f;
	averageH /= count * 4.5f;

	_sprite = make_shared<Sprite>(srvPath, Vector2(averageW, averageH));

	_action = make_shared<Action>(clips, "Bullet" , Action::LOOP, 0.1f);
	_action->Play();
}

void Cup_Bullet::Update()
{
	if (!isActive) return;

	_sprite->GetTransform()->GetPos() += _direction * _speed * DELTA_TIME;

	_collider->Update();

	_action->Update();
	_sprite->Update();
}

void Cup_Bullet::Render()
{
	if (!isActive) return;

	_sprite->SetSpriteAction(_action->GetCurClip());
	_sprite->Render();

	_collider->Render();
}

void Cup_Bullet::SetDirection(Vector2 dir)
{
	float angle = dir.Angle();
	_direction = dir;
	_sprite->GetTransform()->GetAngle() = angle - PI * 0.5f;
}
