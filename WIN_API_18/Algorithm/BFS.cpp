#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

// ���� : ���� �켱 Ž�� : BFS
// BFS�� DFS�� ������

// DFS
// ����Ž�� -> Dynamic Programming -> Deep learning
// -> ���� ��
// -> ����Լ��� ���� ���� ����

// BFS
// ����Ž��

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent;

void CreateGraph()
{
	adjacent = vector<vector<bool>>(6, vector<bool>(6, false));
	discovered = vector<bool>(6, false);
	parent = vector<int>(6, -1);
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

void BFS(int start)
{
	int nodeCount = adjacent.size();
	queue<int> q;
	q.push(start);
	parent[0] = 0;
	discovered[start] = true;

	while (true)
	{
		if (q.empty() == true)
			break;

		int here = q.front();
		q.pop();

		for (int there = 0; there < nodeCount; there++)
		{
			if (there == here)
				continue;
			if (discovered[there] == true)
				continue;
			if (adjacent[here][there] == false)
				continue;

			// ���� �Ǿ��ְ�, �湮�� ���� ��
			q.push(there);
			discovered[there] = true;
			parent[there] = here;
			cout << there << " �߰�!" << endl;
		}
	}
}

int main()
{
	CreateGraph();
	BFS(0);

	cout << "5�� �߰� ���" << parent[5] << endl;

	// 0 ~ 5�� ���� ��ã��

	int here = 5;
	vector<int> path;
	while (true)
	{
		cout << here << endl;
		if (here == 0)
		{
			cout << "������ ã��" << endl;
			break;
		}

		path.push_back(here);
		here = parent[here];
	}

	path.push_back(0);

	std::reverse(path.begin(), path.end());

	return 0;
}