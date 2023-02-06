#include "framework.h"
#include "ItemDataManager.h"

ItemDataManager::ItemDataManager()
{
	CreateTable();
}

ItemDataManager::~ItemDataManager()
{
}

void ItemDataManager::CreateTable()
{
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile("Resource/XML/ItemData.xml");
	assert(document != nullptr);

	tinyxml2::XMLElement* workBook = document->FirstChildElement();
	tinyxml2::XMLElement* workSheet = workBook->FirstChildElement("Worksheet");
	tinyxml2::XMLElement* table = workSheet->FirstChildElement();
	tinyxml2::XMLElement* row = table->FirstChildElement();

	while (true)
	{
		row = row->NextSiblingElement();

		if (row == nullptr)
			break;

		tinyxml2::XMLElement* cell = row->FirstChildElement();
		tinyxml2::XMLElement* data = cell->FirstChildElement();

		ItemData itemData;

		itemData.name = data->GetText();

		vector<UINT> temp;
		while (true)
		{
			cell = cell->NextSiblingElement();
			if (cell == nullptr)
				break;

			data = cell->FirstChildElement();

			temp.push_back(data->IntText());
		}

		itemData.price =		temp[0];
		itemData.endurance =	temp[1];
		itemData.health =		temp[2];
		itemData.attack =		temp[3];
		itemData.frameX =		temp[4];
		itemData.frameY =		temp[5];

		_dataTable[itemData.name] = itemData;
	}

}
