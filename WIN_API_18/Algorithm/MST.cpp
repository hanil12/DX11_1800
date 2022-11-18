#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

vector<vector<int>> adjacent;
vector<bool> discovered;
vector<int> parent;

void CreateGraph()
{
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	discovered = vector<bool>(6, false);
	parent = vector<int>(6, -1);

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

class DisJointSet
{
public:
	DisJointSet(int n)
		: _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	int FindLeader(int u)
	{
		// 기저 사례
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return FindLeader(parent);
	}


	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (vLeader == uLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
			std::swap(uLeader, vLeader);

		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

// MST : 최소 신장(스패닝) 트리
// 1. 노드가 n개일 때, 간선의 개수는 n-1개이다.
// 2. 사이클이 없어야한다.
// 3. 모든 노드를 방문해야한다.

// Kruskal Algorithm
// -> 최소 스패닝 트리 찾기.
// => 탐욕법(greedy algorithm)

// 탐욕법
// 각 부분마다 현재 최선의 선택을 찾아서 답을 구하는 것

struct KruskalEdge
{
	int cost;
	int u; // 시작점
	int v; // 도착점

	bool operator<(const KruskalEdge& edge) const
	{
		if (cost < edge.cost)
			return true;
		return false;
	}
};

int Kruskal(vector<KruskalEdge>& selectEdges)
{
	int result = 0;

	selectEdges.clear();

	vector<KruskalEdge> edges;
	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent[u].size(); v++)
		{
			if (u > v)
				continue;

			int cost = adjacent[u][v];
			if (cost == -1)
				continue;

			edges.push_back({ cost, u, v });
		}
	}

	std::sort(edges.begin(), edges.end());

	DisJointSet sets(adjacent.size());

	for (KruskalEdge& edge : edges)
	{
		// 시작노드와 도착노드가 같은 그룹이면 스킵
		if (sets.FindLeader(edge.u) == sets.FindLeader(edge.v))
			continue;

		// 시작노드와 도착노드가 서로 다른 그룹이면 Merge
		sets.Merge(edge.u, edge.v);
		selectEdges.push_back(edge);
		result += edge.cost;
	}

	return result;
}

int main()
{
	CreateGraph();

	vector<KruskalEdge> mst; // -> 최소신장트리
	int sum = Kruskal(mst);
	cout << sum << endl;

	return 0;
}