#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

string babbling[4] = { "aya", "ye", "woo", "ma" };
vector<bool> visited = vector<bool>(4,false);
unordered_map<string, int> table;

void MakeString(int index ,string str)
{
	// 기저
	if (str.size() >= 10)
		return;

	// 구하기
	string temp = str + babbling[index];
	table[temp]++;
	visited[index] = true;

	for (int i = 1; i < 4; i++)
	{
		int nextIndex = (index + i) % 4;
		if (visited[nextIndex] == true)
			continue;

		MakeString(nextIndex, temp);
	}

	visited[index] = false;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		MakeString(i, "");
	}

	if (table.count("ye") == 1)
		cout << "ye 가 있습니다." << endl;

	return 0;
}