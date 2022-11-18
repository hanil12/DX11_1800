#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

#include "BinarySearchTree.h"

using namespace std;

// Disjoint : 서로소
// Set : 집합

// 그래프, 트리 응용
// 최소 스패닝 트리(최소 신장 트리)

// 길드시스템
// 유저가 1000명 정도

struct User
{
	int guild_id;
};

void GuildSystem()
{
	vector<User> users;
	users.reserve(1000);

	for (int i = 0; i < 1000; i++)
	{
		users.push_back(User({ i }));
	}

	// 1번이랑 5번이랑 같은 길드
	users[1].guild_id = users[5].guild_id;
	// [0] [1] [2] [3] [4] [5]
	//  0   5   2   3   4   5

	// guild가 2인 얘랑 5인 얘랑 통합
	for (auto& user : users)
	{
		if (user.guild_id == 2)
			user.guild_id = 5;
	}
	// [0] [1] [2] [3] [4] [5]
	//  0   5   5   3   4   5

	// N번 째 아이를 찾고 싶다. -> 상수
	// 길드 통합. -> O(N)
}

// 트리구조를 이용한 서로소 집합

// [1]      [3]
// [5]   [2][4]
//          [0]

class NaiveDisJointSet
{
public:
	NaiveDisJointSet(int n)
	: _parent(n)
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	// 너의 최고 대장이 누구야?
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

		_parent[uLeader] = vLeader;
	}

private:
	vector<int> _parent;
};

class DisJointSet
{
public:
	DisJointSet(int n)
		: _parent(n), _rank(n,1)
	{
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}

	// 너의 최고 대장이 누구야?
	int FindLeader(int u)
	{
		// 기저 사례
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return FindLeader(parent);
	}

	// [0][1][2][3][4][5]
	// Merge(0,1)
	// [1] [2] [3] [4] [5]
	// [0]

	// Merge(1,2)
	// [1]     [3] [4] [5]
	// [0][2]

	// Merge(5,4);
	// Merge(5,3);
	// [1]     [4]
	// [0][2]  [3][5]

	// Merge(1,4)
	// [4]
	// [1]   [3][5]
	// [0][2]

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

int main()
{
	NaiveDisJointSet nds(6);
	// [0][1][2][3][4][5]
	//  0  1  2  3  4  5

	cout << nds.FindLeader(0) << endl;
	nds.Merge(2, 0);
	// [0][1][2][3][4][5]
	//  0  1  0  3  4  5
	nds.Merge(0,1);
	// [0][1][2][3][4][5]
	//  1  1  0  3  4  5
	cout << "2의 리더 : " << nds.FindLeader(2) << endl;
	nds.Merge(4, 5);
	nds.Merge(3, 4);
	cout << "3의 리더 : " << nds.FindLeader(3) << endl;

	nds.Merge(5, 0);
	cout << "5의 리더 : " << nds.FindLeader(5) << endl;

	DisJointSet ds(6);
	// [0][1][2][3][4][5]
	//  0  1  2  3  4  5

	cout << ds.FindLeader(0) << endl;
	ds.Merge(0, 1);
	
	ds.Merge(1, 2);
	ds.Merge(5, 4);
	ds.Merge(5, 3);

	ds.Merge(1, 4);

	cout << "5의 Leader : " << ds.FindLeader(5) << endl;

	// [4]
	// [1]    [3] [5]
	// [0][2]

	return 0;
}