#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

// ���� : ���� �켱 Ž�� : BFS
// BFS�� DFS�� ������

struct Vertex
{
	int _data;
};

vector<vector<int>> adjacent; // ���� ����Ʈ
vector<vector<bool>> adjacent;
vector<bool> discovered;

// Win Merge Test

// �׷���
// 0 : 1 2 4
// 1 : 0 2
// 2 : 0 1 3 5
// 3 : 2
// 4 : 0
// 5 : 2

void CreateGraph()
{
	adjacent = vector<vector<int>>(6);
	// [0].. [1 ,2 ,4 ]
	// [1].. [ ]
	// ...

	// ��������Ʈ
	adjacent[0].push_back(1);
	adjacent[0].push_back(2);
	adjacent[0].push_back(4);

	adjacent[1].push_back(0);
	adjacent[1].push_back(2);

	adjacent[2].push_back(0);
	adjacent[2].push_back(1);
	adjacent[2].push_back(3);
	adjacent[2].push_back(5);

	adjacent[3].push_back(2);

	adjacent[4].push_back(0);

	adjacent[5].push_back(2);

	// 0�� ������ 5�� ������ ���� �̾����ֽ��ϱ�?
	for (auto& vertex : adjacent[0])
	{
		if (vertex == 5)
		{
			cout << "0�� ���ؽ��� 5�� ���ؽ��� �̾����ֽ��ϴ�." << endl;
			break;
		}
	}
}

void CreateGraph()
{
	adjacent = vector<vector<bool>>(6, vector<bool>(6, false));
	discovered = vector<bool>(6, false);
	//    [0][1][2][3][4][5]
	// [0] 0  1  1  0  1  0
	// [1] 1  0  1  0  0  0
	// [2] 1  1  0  1  0  1
	// [3] 0  0  1  0  0  0
	// [4] 1  0  0  0  0  0
	// [5] 0  0  1  0  0  0

	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][2] = true;

	adjacent[2][0] = true;
	adjacent[2][1] = true;
	adjacent[2][3] = true;
	adjacent[2][5] = true;

	adjacent[3][2] = true;

	adjacent[4][0] = true;

	adjacent[5][2] = true;

	// 2���� 5�� ����� ������ �ֽ��ϱ�?
	if (adjacent[2][5] == true)
		cout << "����Ǿ��ֽ��ϴ�." << endl;
}

// Ž�� (���� Ž��)
// DFS (Deep First Search)... ���� �켱 Ž��

void DFS(int start)
{
	discovered[start] = true;

	int next;
	for (int i = 0; i < adjacent.size(); i++)
	{
		if (adjacent[start][i] == true)
		{
			if (discovered[i] == true) // �湮�� ���̳�?
				continue;
			next = i;
			DFS(next); // ����Լ�
		}
	}
}

void DFS_ALL()
{
	int count = 0; // ������ ����

	for (int i = 0; i < adjacent.size(); i++)
	{
		if (discovered[i] == false)
		{
			count++;
			DFS(i);
		}
	}

	cout << "������ ���� : " << count << endl;
}

int main()
{
	CreateGraph();
	
	DFS_ALL();

	return 0;
}