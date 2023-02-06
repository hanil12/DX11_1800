#pragma once
class ItemDataManager
{
public:
	ItemDataManager();
	~ItemDataManager();

	ItemData GetItemData(string name) { return _dataTable[name]; }

private:
	void CreateTable();
	unordered_map<string, ItemData> _dataTable;
};

