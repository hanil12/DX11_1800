#include "framework.h"
#include "MazePlayer.h"

MazePlayer::MazePlayer(shared_ptr<Maze> maze)
: _maze(maze)
{
	_pos = _maze->GetStartPos();
	RightHand();
}

MazePlayer::~MazePlayer()
{
	_maze = nullptr;
}

void MazePlayer::RightHand()
{
	Vector2 curPos = _pos;
	Vector2 destPos = _maze->GetEndPos();

	Vector2 frontDir[4] =
	{
		Vector2(0,-1), // UP
		Vector2(-1,0),
		Vector2(0,1),
		Vector2(1,0)
	};

	_path.reserve(1000);
	while (curPos != destPos)
	{
		// 1. ���� �ٶ󺸴� ������ �������� ���������� �� �� �ִ��� Ȯ��
		int newDir = (_dir - 1 + DIRCOUNT) % DIRCOUNT;

		if (Cango(curPos + frontDir[newDir]))
		{
			curPos += frontDir[newDir];
			_dir = static_cast<Dir>(newDir);

			_path.push_back(curPos);
		}

		// 2. (1�� ������� ��)���� �ٶ󺸴� �������� ������ �� �ִ��� Ȯ��
		else if (Cango(curPos + frontDir[_dir]))
		{
			curPos += frontDir[_dir];

			_path.push_back(curPos);
		}

		// 3. (1,2 �Ѵ� ������� ��) �������� ȸ��
		else
		{
			_dir = static_cast<Dir>((_dir + 1) % DIRCOUNT);
		}
	}
}

void MazePlayer::Update()
{
	if (_pathIndex >= _path.size())
		return;

	if (_time >= 1.0f)
	{
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			Vector2 temp = _path[_pathIndex - 1];
			_maze->GetBlock(temp)->Type() = MazeBlock::BlockType::ABLE;
		}

		_time = 0.0f;
		_pathIndex++;
	}

	_time += 0.2f;
}

bool MazePlayer::Cango(const Vector2& pos)
{
	if (_maze->GetBlockType(pos) == MazeBlock::BlockType::DISABLE || 
		_maze->GetBlockType(pos) == MazeBlock::BlockType::NONE)
		return false;

	return true;
}
