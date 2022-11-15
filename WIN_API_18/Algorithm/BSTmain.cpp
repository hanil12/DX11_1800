#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

#include "BinarySearchTree.h"

using namespace std;

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

	return 0;
}