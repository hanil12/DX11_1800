#pragma once
class ItemIcon
{
public:
	enum ItemKinds
	{
		NONE,
		SWORD, // 100 ~ 199
		ARMOR, // 200 ~ 299
		SHOES, // 300 ~ 399
		POTION, // 400 ~ 499
		LAMP, // 500 ~ 599
		BEER // 600 ~ 699
	};

	ItemIcon(UINT id, string name);
	~ItemIcon();

	void Update();
	void PostRender();

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }
	void SetItemIcon(ItemData data);
	void SetItemIconScale(float value) { _sprite->GetTransform()->GetScale() *= value; }
	void SetItemIconPos(Vector2 pos) { _sprite->GetTransform()->GetPos() = pos; }

private:
	void CreateIcon();

	UINT _itemID = 0;
	string _name;
	shared_ptr<Sprite> _sprite;
};

