#pragma once
class InventoryScene : public Scene
{
public:
	InventoryScene();
	virtual ~InventoryScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<ItemDataManager> _dataManager;
	shared_ptr<ItemInventory> _inventory;
	shared_ptr<Store> _store;
};

