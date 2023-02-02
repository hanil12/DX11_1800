#include "framework.h"
#include "InventoryScene.h"
#include "Scene\BagicScene\InventoryScene.h"

InventoryScene::InventoryScene()
{
	_inventory = make_shared<ItemInventory>();
	_inventory->SetPos({ CENTER_X, CENTER_Y });
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
