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
		button->SetEvent_INT(std::bind(&Store::SetCurItem,this,i));
		_buttons.push_back(button);
	}

	LoadSlotPos();

	_buyButton = make_shared<Button>(L"UI/Button.png");
	_buyButton->SetScale(Vector2(0.1f, 0.1f));
	_buyButton->SetParent(_bg->GetTransform());
	_buyButton->SetPostion(Vector2(0.0f, -200.0f));
	Button::TextInfo text;
	_buyButton->SetText(text);
	_buyButton->SetEvent(std::bind(&Store::BuyItem, this));
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
	_buyButton->Update();
}

void Store::PostRender()
{
	_bg->Render();
	for (auto icon : _icons)
		icon->PostRender();

	for (auto button : _buttons)
		button->PostRender();

	_buyButton->PostRender();

	ItemData data = _curItemData;
	string text = "Item Name: " + data.name;
	ImGui::Text(text.c_str());
	ImGui::SliderInt("Item Price", (int*)&data.price, 0, 10000);
	ImGui::SliderInt("Item Endurance", (int*)&data.endurance, 0, 10000);
	ImGui::SliderInt("Item Health", (int*)&data.health, 0, 10000);
	ImGui::SliderInt("Item Attack", (int*)&data.attack, 0, 10000);
}

void Store::SetItems()
{
	if (_dataManager.expired() == false)
	{
		_itemDataes[0] = _dataManager.lock()->GetItemData("Sword");
		_itemDataes[1] = _dataManager.lock()->GetItemData("Armor");
		_itemDataes[2] = _dataManager.lock()->GetItemData("Axe");
		_itemDataes[3] = _dataManager.lock()->GetItemData("Potion");
		_itemDataes[4] = _dataManager.lock()->GetItemData("Lamp");
		_itemDataes[5] = _dataManager.lock()->GetItemData("Shoes");
	}

	for (int i = 0; i < 9; i++)
	{
		_icons[i]->SetItemIcon(_itemDataes[i]);
	}
}

void Store::SetCurItem(int index)
{
	_curItemData = _itemDataes[index];
}

void Store::BuyItem()
{
	if (_inventory.expired())
		return;

	if(_curItemData.name != "")
		_inventory.lock()->BuyItem(_curItemData);
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
