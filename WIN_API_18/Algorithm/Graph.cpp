#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

// 과제 : 넓이 우선 탐색 : BFS
// BFS와 DFS의 차이점

struct Vertex
{
	int _data;
};

vector<vector<int>> adjacent; // 인접 리스트
vector<vector<bool>> adjacent;
vector<bool> discovered;

// Win Merge Test

// 그래프
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

	// 인접리스트
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

	// 0번 정점과 5번 정점이 서로 이어져있습니까?
	for (auto& vertex : adjacent[0])
	{
		if (vertex == 5)
		{
			cout << "0번 버텍스와 5번 버텍스가 이어져있습니다." << endl;
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

	// 2에서 5로 연결된 간선이 있습니까?
	if (adjacent[2][5] == true)
		cout << "연결되어있습니다." << endl;
}

// 탐색 (완전 탐색)
// DFS (Deep First Search)... 깊이 우선 탐색

void DFS(int start)
{
	discovered[start] = true;

	int next;
	for (int i = 0; i < adjacent.size(); i++)
	{
		if (adjacent[start][i] == true)
		{
			if (discovered[i] == true) // 방문한 곳이냐?
				continue;
			next = i;
			DFS(next); // 재귀함수
		}
	}
}

void DFS_ALL()
{
	int count = 0; // 뭉탱이 개수

	for (int i = 0; i < adjacent.size(); i++)
	{
		if (discovered[i] == false)
		{
			count++;
			DFS(i);
		}
	}

	cout << "뭉탱이 개수 : " << count << endl;
}

int main()
{
	CreateGraph();
	
	DFS_ALL();

	return 0;
}