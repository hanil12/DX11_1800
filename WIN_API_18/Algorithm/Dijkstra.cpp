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
	int _vertex; // ��� ��ȣ
	int _cost; // ����ġ

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

		// ���� ���� �ĺ��� ã��.
		// ���� ª�� �Ÿ� Ž��.
		int cost = pq.top()._cost;
		here = pq.top()._vertex;
		pq.pop();

		// �� ª�� ��θ� �ڴʰ� ã�Ҵٸ� ��ŵ
		if (best[here] < cost)
		{
			cout << here << endl;
			cout << cost << endl;
			cout << best[here] << endl;
			continue;
		}

		// �湮
		for (int there = 0; there < 6; there++)
		{
			if (here == there)
				continue;

			// ����?
			if (adjacent[here][there] == -1)
				continue;

			// �� ���� ��� ���ſ� ã������ ��ŵ
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
		cout << i << "�� �������׼� �߰�? " << parent[i] << endl;
		cout << "0���������� �Ÿ�" << best[i] << endl;
	}
}

int main()
{
	CreateGraph();
	Dijkstra(0);

	return 0;
}