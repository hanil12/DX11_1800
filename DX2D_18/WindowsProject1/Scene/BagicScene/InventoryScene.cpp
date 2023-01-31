#include "framework.h"
#include "InventoryScene.h"
#include "Scene\BagicScene\InventoryScene.h"

InventoryScene::InventoryScene()
{
	_icon = make_shared<ItemIcon>();


}

InventoryScene::~InventoryScene()
{
}

void InventoryScene::Update()
{
	_icon->SetIcon("Sword", { CENTER_X, CENTER_Y });
}

void InventoryScene::Render()
{
	_icon->Render();
}
