#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

// 과제 : 넓이 우선 탐색 : BFS
// BFS와 DFS의 차이점

// DFS
// 완전탐색 -> Dynamic Programming -> Deep learning
// -> 닫힌 계
// -> 재귀함수로 쉽게 구현 가능

// BFS
// 완전탐색

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

	// 2에서 5로 연결된 간선이 있습니까?
	if (adjacent[2][5] == true)
		cout << "연결되어있습니다." << endl;
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

			// 연결 되어있고, 방문도 안한 곳
			q.push(there);
			discovered[there] = true;
			parent[there] = here;
			cout << there << " 발견!" << endl;
		}
	}
}

int main()
{
	CreateGraph();
	BFS(0);

	cout << "5의 발견 노드" << parent[5] << endl;

	// 0 ~ 5로 가는 길찾기

	int here = 5;
	vector<int> path;
	while (true)
	{
		cout << here << endl;
		if (here == 0)
		{
			cout << "시작점 찾음" << endl;
			break;
		}

		path.push_back(here);
		here = parent[here];
	}

	path.push_back(0);

	std::reverse(path.begin(), path.end());

	return 0;
}