#pragma once
class ItemInventory
{
public:
	ItemInventory();
	~ItemInventory();

	void Update();
	void PostRender();

	void SetPos(Vector2 pos) { _bg->GetTransform()->GetPos() = pos; }

	void SaveSlotPos();
	void LoadSlotPos();

	void SetItemIcon(int slot, ItemData data);

	bool debug = false;

	void SetItemManager(shared_ptr<ItemDataManager> itemDataManager) { if (_dataManager.expired() == true) { _dataManager = itemDataManager; } }

	void BuyItem(ItemData itemdata);
private:
	shared_ptr<Quad> _bg;

	vector<shared_ptr<ItemIcon>> _icons;
	vector<ItemData>			 _itemDataes;

	weak_ptr<ItemDataManager> _dataManager;

	UINT _money = 1000;
};

