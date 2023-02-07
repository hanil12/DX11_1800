#include "framework.h"
#include "InventoryScene.h"
#include "Scene\BagicScene\InventoryScene.h"

InventoryScene::InventoryScene()
{
	_dataManager = make_shared<ItemDataManager>();

	_inventory = make_shared<ItemInventory>();
	_inventory->SetPos({ CENTER_X + 300, CENTER_Y });
	_inventory->SetItemManager(_dataManager);

	_store = make_shared<Store>();
	_store->SetPos({ CENTER_X - 300, CENTER_Y });
}

InventoryScene::~InventoryScene()
{
}

void InventoryScene::Update()
{
	_inventory->Update();
	_store->Update();
}

void InventoryScene::Render()
{
	_store->PostRender();
	_inventory->PostRender();
}

void InventoryScene::PostRender()
{
	if (ImGui::Button("Sword", { 100,100 }))
	{
		_inventory->SetItemIcon(0, _dataManager->GetItemData("Sword"));
	}
}
