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

	CreateMap();
}

Maze::~Maze()
{
	_player = nullptr;
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

	Vector2 playerPos = _player->GetPos();
	_blocks[(UINT)playerPos._y][(UINT)playerPos._x]->Type() = MazeBlock::BlockType::PLAYER;
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
