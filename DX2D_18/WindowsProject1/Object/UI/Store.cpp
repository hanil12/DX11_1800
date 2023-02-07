#include "framework.h"
#include "Store.h"

Store::Store()
{
	_bg = make_shared<Quad>(L"UI/InventoryPanel.png");
	// 512, 512

	_itemDataes.resize(9);

	for (int i = 0; i < 9; i++)
	{
		shared_ptr<ItemIcon> icon = make_shared<ItemIcon>(0, "");
		icon->SetItemIconScale(0.7f);
		icon->GetTransform()->SetParent(_bg->GetTransform());
		_icons.push_back(icon);

		shared_ptr<Button> button = make_shared<Button>(icon->IconSize());
		button->SetParent(icon->GetTransform());
		_buttons.push_back(button);
	}

	LoadSlotPos();
}

Store::~Store()
{
}

void Store::Update()
{
	for (auto icon : _icons)
		icon->Update();

	for (auto button : _buttons)
		button->Update();

	_bg->Update();
}

void Store::PostRender()
{
	_bg->Render();
	for (auto icon : _icons)
		icon->PostRender();

	for (auto button : _buttons)
		button->PostRender();
}

void Store::LoadSlotPos()
{
	BinaryReader reader = BinaryReader(L"Save/InventorySlotSetting.setting");

	vector<Vector2> temp;
	UINT size = reader.UInt();
	temp.resize(size);

	void* ptr = temp.data();
	reader.Byte(&ptr, sizeof(Vector2) * size);

	for (int i = 0; i < 9; i++)
	{
		_icons[i]->GetTransform()->GetPos() = temp[i];
	}
}
