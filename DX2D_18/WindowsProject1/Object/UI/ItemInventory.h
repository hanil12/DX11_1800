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

	bool debug = false;
private:
	shared_ptr<Quad> _bg;

	vector<shared_ptr<ItemIcon>> _icons;
};

