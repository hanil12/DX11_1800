#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

#include "BinarySearchTree.h"

using namespace std;

class Player
{
public:

	int _id;
	int _hp;
};

int main()
{
	//	vector<int> t = { 2,10, 56,80,90,120, };
	BinarySearchTree tree;

	tree.Insert(56);
	tree.Insert(90);
	tree.Insert(80);
	tree.Insert(10);
	tree.Insert(2);
	tree.Insert(120);

	tree.PrintTree(tree._root);

	map<int, int> myMap;

	myMap[120] = 0;
	myMap[10] = 0;
	myMap[56] = 0;
	myMap[80] = 0;
	myMap[2] = 0;
	myMap[90] = 0;

	myMap.insert(make_pair<int, int>(100, 1)); // pair first: Ű, second : data

	return 0;
}