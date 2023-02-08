#pragma once
class Store
{
public:
	Store();
	~Store();

	void Update();
	void PostRender();

	void SetPos(Vector2 pos) { _bg->GetTransform()->GetPos() = pos; }
	void SetItemManager(shared_ptr<ItemDataManager> manager) { _dataManager = manager; }
	void SetInventory(shared_ptr<ItemInventory> inventory) { _inventory = inventory; }
	void SetItems();
	void SetCurItem(int index);

	void BuyItem();

private:

	void LoadSlotPos();

	shared_ptr<Quad> _bg;

	vector<shared_ptr<ItemIcon>> _icons;
	vector<shared_ptr<Button>> _buttons;
	vector<ItemData>			 _itemDataes;

	weak_ptr<ItemDataManager> _dataManager;
	weak_ptr<ItemInventory> _inventory;

	ItemData _curItemData;

	shared_ptr<Button> _buyButton;
};

