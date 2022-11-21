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

	CreateMap_Prim();
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
	// ��� �ձ�
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

	// �������� ���� Ȥ�� �Ʒ��� ���� �մ� �۾�
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			// ������ �� �۾�... ��� �ձ�
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// ������
			if (x == _poolCountX - 2 && y == _poolCountY - 2)
			{
				_blocks[y][x]->Type() = MazeBlock::BlockType::END;
				continue;
			}

			// HACKCODE
			// ���������κ��� ���� �� ABLE�� �б�
			if (x == _poolCountX - 2)
			{
				_blocks[y + 1][x]->Type() = MazeBlock::BlockType::ABLE;
				continue;
			}

			// ���������κ��� ���� �� ABLE�� �б�
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
	// ��� �ձ�
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
			// ������ �� �۾�... ��� �ձ�
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// ��� �ĺ��� ��Ƴ��� �۾�
			// �������� �����ϴ� ���� �ĺ�
			if (x < _poolCountX - 2)
			{
				const int randValue = rand() % 100;
				Kruskal_edge edge;
				edge.cost = randValue;
				edge.u = Vector2(x,y);
				edge.v = Vector2(x + 2, y);

				edges.push_back(edge);
			}
			
			// �Ʒ������� �����ϴ� ���� �ĺ�
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

		// �׷��̸� ��ŵ
		if (sets.FindLeader(u) == sets.FindLeader(v))
			continue;

		sets.Merge(u, v);

		// �ʿ� ����... 
		int x = (edge.u._x + edge.v._x) / 2;
		int y = (edge.u._y + edge.v._y) / 2;

		_blocks[y][x]->Type() = MazeBlock::BlockType::ABLE;
	}
}

void Maze::CreateMap_Prim()
{
	// ��� �ձ�
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

	// Vector2 u
	// edges[u] : u��� ������ ����� ���� ���
	map<Vector2, vector<Prim_edge>> edges;

	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// ��� �ĺ��� ��Ƴ��� �۾�
			// �������� �����ϴ� ���� �ĺ�
			if (x < _poolCountX - 2)
			{
				const int randValue = rand() % 100;
				Vector2 u = Vector2{ x,y };
				Vector2 v = Vector2{ x + 2, y };
				edges[u].push_back({ randValue, v });
				edges[v].push_back({ randValue, u });
			}

			if (y < _poolCountY - 2)
			{
				const int randValue = rand() % 100;
				Vector2 u = Vector2{ x,y };
				Vector2 v = Vector2{ x, y + 2};
				edges[u].push_back({ randValue, v });
				edges[v].push_back({ randValue, u });
			}
		}
	}

	// �ش� ������ ���տ� ������ �Ǿ��ֳ�?
	map<Vector2, bool> added;
	// � ������ ������ ���� ������ �Ǿ��ִ���
	map<Vector2, Vector2> parent;
	// ����� �ִ� ���տ� ������ ���� ��, �ش� ������ ��� �ּ� ������ ����
	map<Vector2, int> best;

	// ���ͽ�Ʈ��� ���� ����������
	// �����˰����� ù �������� �ƴ϶� ��ü ���տ����� �Ÿ�

	// added, best �ʱ�ȭ
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			best[Vector2{ x,y }] = INT_MAX;
			added[Vector2{ x,y }] = false;
		}
	}

	priority_queue<Prim_edge> pq;
	Vector2 startPos = { 1,1 };
	pq.push(Prim_edge({ 0, startPos }));
	best[startPos] = 0;
	parent[startPos] = startPos;

	while (true)
	{
		if (pq.empty() == true)
			break;

		Prim_edge bestEdge = pq.top();
		pq.pop();

		// ���� ����� ����
		Vector2 vertex = bestEdge.v;

		// �̹� �߰��Ǿ����� ��ŵ
		if (added[vertex])
			continue;

		added[vertex] = true;

		// �ʿ� ����
		{
			int x = (parent[vertex]._x + vertex._x) / 2;
			int y = (parent[vertex]._y + vertex._y) / 2;

			_blocks[y][x]->Type() = MazeBlock::BlockType::ABLE;
		}

		// ��� �߰��� ������ ������ �������� �����Ѵ�.
		for (Prim_edge& edge : edges[vertex])
		{
			// �̹� �߰��Ǿ��ִ� ��� ��ŵ
			if (added[edge.v])
				continue;

			// �ٸ� ��η� �� ���� �ĺ��� �߰��� �Ǿ��־����� ��ŵ
			if (edge.cost > best[edge.v])
				continue;

			best[edge.v] = edge.cost;
			parent[edge.v] = vertex;
			pq.push(edge);
		}
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
