#include "framework.h"
#include "ItemIcon_Instance.h"

ItemIcon_Instance::ItemIcon_Instance()
{
	_quad = make_shared<Quad>(L"Item_11x5.png");
	_quad->SetVertexShader(ADD_VS(L"ItemIconVertexShader"));
	_quad->SetPixelShader(ADD_PS(L"ItemIconPixelShader"));

	SetItemIconTable();
	_instanceBuffer = make_shared<VertexBuffer>(_instanceData.data(), sizeof(InstanceData), _poolCount * _itemCount,0,true);
}

ItemIcon_Instance::~ItemIcon_Instance()
{
}

void ItemIcon_Instance::Render()
{
	_instanceBuffer->IASet(1);

	_quad->SetRender();

	DC->DrawIndexedInstanced(6, _poolCount * _itemCount, 0, 0, 0);
}

void ItemIcon_Instance::SetIcon(string name, Vector2 pos)
{
	if (_iconTable.count(name) == 0)
		return;

	for (auto& icon : _iconTable[name])
	{
		if (icon.isActive == false)
		{
			icon.isActive = true;
			icon.transform->GetPos() = pos;
			icon.transform->SetSRT();
			icon.data->matrix = XMMatrixTranspose(*icon.transform->GetMatrix());

			break;
		}
	}
}

void ItemIcon_Instance::SetItemIconTable()
{
	_instanceData.reserve(_poolCount * _itemCount);
	for (int i = 0; i < _itemCount; i++)
	{
		for (int j = 0; j < _poolCount; j++)
		{
			IconData data;
			InstanceData ins_data;
			ins_data.maxFrame = Vector2(11, 5);
			data.isActive = false;

			data.transform = make_shared<Transform>();
			data.transform->GetPos().x = -3000.0f;
			data.transform->GetScale().x /= 11.0f;
			data.transform->GetScale().y /= 5.0f;
			data.transform->SetSRT();

			ins_data.matrix = XMMatrixTranspose(*data.transform->GetMatrix());

			string itemName;

			switch (i)
			{
			case 0:
			{
				ins_data.curFrame = { 0,0 };
				itemName = "Sword";
				break;
			}

			case 1:
			{
				ins_data.curFrame = { 1,0 };
				itemName = "Armor";
				break;
			}

			case 2:
			{
				ins_data.curFrame = { 2,0 };
				itemName = "Shoes";
				break;
			}

			case 3:
			{
				ins_data.curFrame = { 3,0 };
				itemName = "Lamp";
				break;
			}

			case 4:
			{
				ins_data.curFrame = { 4,0 };
				itemName = "Potion";
				break;
			}

			case 5:
			{
				ins_data.curFrame = { 5,3 };
				itemName = "Axe";
				break;
			}

			default:
				break;
			}

			_instanceData.push_back(ins_data);
			data.data = &_instanceData.back();
			data.name = itemName;
			_iconTable[itemName].push_back(data);
		}
	}
}
