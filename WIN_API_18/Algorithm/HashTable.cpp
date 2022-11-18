#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
	map<int, int> myMap;
	unordered_map<int, int> myUmap;

	myUmap[0] = 1;
	myUmap[1] = 2;
	myUmap[4] = 5;
	myUmap[2] = 3;
	myUmap[3] = 4;

	for (auto& pair : myUmap)
	{
		cout << "Key: " << pair.first << " Value: " << pair.second << endl;
	}

	myMap[0] = 1;
	myMap[1] = 2;
	myMap[4] = 5;
	myMap[2] = 3;
	myMap[3] = 4;

	for (auto& pair : myMap)
	{
		cout << "Key: " << pair.first << " Value: " << pair.second << endl;
	}

	return 0;
}