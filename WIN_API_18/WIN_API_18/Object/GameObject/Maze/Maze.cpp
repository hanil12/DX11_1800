#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	Vector2 offset = Vector2{ CENTER_X * 0.5f + 50.0f, CENTER_Y * 0.5f  - 100.0f};

	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();

			block->SetCenter(Vector2(17 * x + offset._x, 17 * y + offset._y));
			block->Type() = MazeBlock::BlockType::ABLE;
			_blocks[y][x] = block;
		}
	}

	CreateMap_Kruskal();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->Render(hdc);
		}
	}
}

void Maze::CreateMap()
{
	// 노드 뚫기
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_blocks[y][x]->Type() = MazeBlock::BlockType::DISABLE;
			else
				_blocks[y][x]->Type() = MazeBlock::BlockType::ABLE;
		}
	}

	// 랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			// 위에서 한 작업... 노드 뚫기
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// 끝지점
			if (x == _poolCountX - 2 && y == _poolCountY - 2)
			{
				_blocks[y][x]->Type() = MazeBlock::BlockType::END;
				continue;
			}

			// HACKCODE
			// 끝지점으로부터 왼쪽 쭉 ABLE로 밀기
			if (x == _poolCountX - 2)
			{
				_blocks[y + 1][x]->Type() = MazeBlock::BlockType::ABLE;
				continue;
			}

			// 끝지점으로부터 위쪽 쭉 ABLE로 밀기
			if (y == _poolCountY - 2)
			{
				_blocks[y][x + 1]->Type() = MazeBlock::BlockType::ABLE;
				continue;
			}

			const int randValue = rand() % 2; // HACKCODE
			if (randValue == 0)
				_blocks[y][x + 1]->Type() = MazeBlock::BlockType::ABLE;
			else
				_blocks[y + 1][x]->Type() = MazeBlock::BlockType::ABLE;
		}
	}
}

void Maze::CreateMap_Kruskal()
{
	// 노드 뚫기
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_blocks[y][x]->Type() = MazeBlock::BlockType::DISABLE;
			else
				_blocks[y][x]->Type() = MazeBlock::BlockType::ABLE;
		}
	}

	vector<Kruskal_edge> edges;

	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			// 위에서 한 작업... 노드 뚫기
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// 모든 후보를 담아놓는 작업
			// 우측으로 연결하는 간선 후보
			if (x < _poolCountX - 2)
			{
				const int randValue = rand() % 100;
				Kruskal_edge edge;
				edge.cost = randValue;
				edge.u = Vector2(x,y);
				edge.v = Vector2(x + 2, y);

				edges.push_back(edge);
			}
			
			// 아래쪽으로 연결하는 간선 후보
			if (y < _poolCountY - 2)
			{
				const int randValue = rand() % 100;
				Kruskal_edge edge;
				edge.cost = randValue;
				edge.u = Vector2(x,y);
				edge.v = Vector2(x, y + 2);

				edges.push_back(edge);
			}
		}
	}

	std::sort(edges.begin(), edges.end());

	DisJointSet sets(_poolCountX * _poolCountY);

	for (auto& edge : edges)
	{
		int u = edge.u._x + edge.u._y * _poolCountY;
		int v = edge.v._x + edge.v._y * _poolCountY;

		// 그룹이면 스킵
		if (sets.FindLeader(u) == sets.FindLeader(v))
			continue;

		sets.Merge(u, v);

		// 맵에 적용... 
		int x = (edge.u._x + edge.v._x) / 2;
		int y = (edge.u._y + edge.v._y) / 2;

		_blocks[y][x]->Type() = MazeBlock::BlockType::ABLE;
	}
}

MazeBlock::BlockType Maze::GetBlockType(const Vector2& pos)
{
	int blockY = pos._y;
	int blockX = pos._x;
	return _blocks[blockY][blockX]->Type();
}

shared_ptr<MazeBlock> Maze::GetBlock(const Vector2& pos)
{
	return _blocks[static_cast<int>(pos._y)][static_cast<int>(pos._x)];
}
