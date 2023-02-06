#include "framework.h"
#include "ItemInventory.h"

ItemInventory::ItemInventory()
{
	_bg = make_shared<Quad>(L"UI/InventoryPanel.png");
	// 512, 512

	for (int i = 0; i < 9; i++)
	{
		shared_ptr<ItemIcon> icon = make_shared<ItemIcon>(200, "Armor");
		icon->SetItemIconScale(0.7f);
		icon->GetTransform()->SetParent(_bg->GetTransform());
		_icons.push_back(icon);
	}

	LoadSlotPos();
}

ItemInventory::~ItemInventory()
{
}

void ItemInventory::Update()
{
	for (auto icon : _icons)
		icon->Update();
	_bg->Update();
}

void ItemInventory::PostRender()
{
	_bg->Render();
	for (auto icon : _icons)
		icon->PostRender();

	if (debug == false)
		return;
	ImGui::SliderFloat2("ItemIconX1", (float*)(&_icons[0]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX2", (float*)(&_icons[1]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX3", (float*)(&_icons[2]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX4", (float*)(&_icons[3]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX5", (float*)(&_icons[4]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX6", (float*)(&_icons[5]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX7", (float*)(&_icons[6]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX8", (float*)(&_icons[7]->GetTransform()->GetPos()), -512, 512);
	ImGui::SliderFloat2("ItemIconX9", (float*)(&_icons[8]->GetTransform()->GetPos()), -512, 512);

	if (ImGui::Button("SaveSlotSetting", { 100,100 }))
	{
		SaveSlotPos();
	}

	if (ImGui::Button("LoadSlotSetting", { 100,100 }))
	{
		LoadSlotPos();
	}
}

void ItemInventory::SaveSlotPos()
{
	if (debug == false)
		return;

	BinaryWriter writer = BinaryWriter(L"Save/InventorySlotSetting.setting");

	vector<Vector2> temp;
	for (int i = 0; i < 9; i++)
	{
		temp.push_back(_icons[i]->GetTransform()->GetPos());
	}

	writer.UInt(temp.size());
	writer.Byte(temp.data(), sizeof(Vector2) * temp.size());
}

void ItemInventory::LoadSlotPos()
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

void ItemInventory::SetItemIcon(int slot, ItemData data)
{
	if (slot < 0 || slot > _icons.size() - 1)
		return;

	_icons[slot]->SetItemIcon(data);
}
