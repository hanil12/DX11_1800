#include "framework.h"
#include "InventoryScene.h"
#include "Scene\BagicScene\InventoryScene.h"

InventoryScene::InventoryScene()
{
	_dataManager = make_shared<ItemDataManager>();

	_inventory = make_shared<ItemInventory>();
	_inventory->SetPos({ CENTER_X, CENTER_Y });
	_inventory->SetItemManager(_dataManager);
}

InventoryScene::~InventoryScene()
{
}

void InventoryScene::Update()
{
	_inventory->Update();
}

void InventoryScene::Render()
{
	_inventory->PostRender();
}

void InventoryScene::PostRender()
{
	if (ImGui::Button("Sword", { 100,100 }))
	{
		_inventory->SetItemIcon(0, _dataManager->GetItemData("Sword"));
	}
}
