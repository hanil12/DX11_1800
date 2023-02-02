#pragma once
class InventoryScene : public Scene
{
public:
	InventoryScene();
	virtual ~InventoryScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<ItemInventory> _inventory;
};

