// Dijkstra
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

struct Vertex
{
	int _vertex; // 노드 번호
	int _cost; // 가중치

	bool operator<(const Vertex& other) const
	{
		if (_cost < other._cost)
			return true;

		return false;
	}

	bool operator>(const Vertex& other) const
	{
		if (_cost > other._cost)
			return true;

		return false;
	}
};

vector<Vertex> vertices;

vector<vector<int>> adjacent;
vector<bool> discovered;
vector<int> parent;

void CreateGraph()
{
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	discovered = vector<bool>(6, false);
	parent = vector<int>(6, -1);
	//    [0][1][2][3][4][5]
	// [0] 0  2 10 -1  5  -1
	// [1] 2  0  3 -1 -1  -1
	// [2]10  3  0  4 -1  5
	// [3]-1 -1  4  0 -1  -1
	// [4] 5 -1 -1 -1  0  -1
	// [5]-1 -1  5 -1 -1  0

	adjacent[0][1] = 2;
	adjacent[0][2] = 10;
	adjacent[0][4] = 5;

	adjacent[1][0] = 2;
	adjacent[1][2] = 3;

	adjacent[2][0] = 10;
	adjacent[2][1] = 3;
	adjacent[2][3] = 4;
	adjacent[2][5] = 5;

	adjacent[3][2] = 4;

	adjacent[4][0] = 5;

	adjacent[5][2] = 5;
}

void Dijkstra(int here)
{
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
	vector<int> best(6, INT_MAX);
	vector<int> parent(6, -1);

	pq.push(Vertex{ here,0 });
	best[here] = 0;
	discovered[here] = true;
	parent[here] = here;

	while (true)
	{
		if (pq.empty() == true)
			break;

		// 제일 좋은 후보를 찾기.
		// 제일 짧은 거리 탐색.
		int cost = pq.top()._cost;
		here = pq.top()._vertex;
		pq.pop();

		// 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost)
		{
			cout << here << endl;
			cout << cost << endl;
			cout << best[here] << endl;
			continue;
		}

		// 방문
		for (int there = 0; there < 6; there++)
		{
			if (here == there)
				continue;

			// 인접?
			if (adjacent[here][there] == -1)
				continue;

			// 더 좋은 경로 과거에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;

			pq.push(Vertex{ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		cout << i << "는 누구한테서 발견? " << parent[i] << endl;
		cout << "0에서부터의 거리" << best[i] << endl;
	}
}

int main()
{
	CreateGraph();
	Dijkstra(0);

	return 0;
}