#pragma once
class ItemIcon
{
public:
	struct InstanceData
	{
		Vector2 maxFrame;
		Vector2 curFrame;
		XMMATRIX matrix;
	};

	struct IconData
	{
		bool isActive;
		string name;
		InstanceData* data;
		shared_ptr<Transform> transform;
	};

	ItemIcon();
	~ItemIcon();

	void Render();

	void SetIcon(string name, Vector2 pos);

private:
	void SetItemIconTable();

	unordered_map<string, vector<IconData>> _iconTable;
	shared_ptr<Quad> _quad;

	vector<InstanceData> _instanceData;

	shared_ptr<VertexBuffer> _instanceBuffer;

	UINT _poolCount = 30;
	UINT _itemCount = 6;
};

