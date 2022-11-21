#pragma once

struct Kruskal_edge
{
	int cost = 0;
	Vector2 u;
	Vector2 v;

	bool operator<(const Kruskal_edge& edge) const
	{
		if (cost < edge.cost)
			return true;

		return false;
	}
};

struct Prim_edge
{
	int cost = 0;
	Vector2 v;

	bool operator<(const Prim_edge& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const Prim_edge& other) const
	{
		return cost > other.cost;
	}
};

class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMap();
	void CreateMap_Kruskal();
	void CreateMap_Prim();

	Vector2 GetStartPos() { return Vector2(1, 1); }
	Vector2 GetEndPos() { return Vector2(23, 23); }

	MazeBlock::BlockType GetBlockType(const Vector2& pos);
	shared_ptr<MazeBlock> GetBlock(const Vector2& pos);

private:
	shared_ptr<MazeBlock> _blocks [25][25];

	UINT _poolCountX = 25;
	UINT _poolCountY = 25;
};

