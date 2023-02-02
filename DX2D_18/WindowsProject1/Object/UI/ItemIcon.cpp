#include "framework.h"
#include "ItemIcon.h"


ItemIcon::ItemIcon(UINT id, string name)
: _itemID(id)
, _name(name)
{
	CreateIcon();
}

ItemIcon::~ItemIcon()
{
}

void ItemIcon::Update()
{
	_sprite->Update();
}

void ItemIcon::PostRender()
{
	_sprite->Render();
}

void ItemIcon::CreateIcon()
{
	_sprite = make_shared<Sprite>(L"Item_11x5.png", Vector2(11, 5), Vector2(100, 100));

	ItemKinds kind = ItemKinds(_itemID / 100);

	switch (kind)
	{
	case ItemIcon::NONE:
		_sprite->SetSpriteByFrame(Vector2(10, 4));
		break;
	case ItemIcon::SWORD:
		_sprite->SetSpriteByFrame(Vector2(0,0));
		break;
	case ItemIcon::ARMOR:
		_sprite->SetSpriteByFrame(Vector2(1,0));
		break;
	case ItemIcon::SHOES:
		_sprite->SetSpriteByFrame(Vector2(2,0));
		break;
	case ItemIcon::POTION:
		_sprite->SetSpriteByFrame(Vector2(4,0));
		break;
	case ItemIcon::LAMP:
		_sprite->SetSpriteByFrame(Vector2(3,0));
		break;
	case ItemIcon::BEER:
		_sprite->SetSpriteByFrame(Vector2(5,0));
		break;
	default:
		break;
	}
}
