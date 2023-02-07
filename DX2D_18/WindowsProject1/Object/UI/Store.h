#pragma once
class Store
{
public:
	Store();
	~Store();

	void Update();
	void PostRender();

	void SetPos(Vector2 pos) { _bg->GetTransform()->GetPos() = pos; }

private:
	void LoadSlotPos();

	shared_ptr<Quad> _bg;

	vector<shared_ptr<ItemIcon>> _icons;
	vector<shared_ptr<Button>> _buttons;
	vector<ItemData>			 _itemDataes;

	weak_ptr<ItemDataManager> _dataManager;
};

