#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	// 새로운 노드 넣을 자리 찾기
	while (true)
	{
		// 깊이 끝까지 갔는데 노드가 없을 때
		if (node == nullptr)
			break;
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BinarySearchTree::PrintTree(Node* root)
{
	// 3가지 순회방법
	// 전위순회 : 루트부터 순회
	// 중위순회 : 왼쪽 아래부터 ~ 루트 ~ 오른쪽 아래까지
	// 후위순회 : 루트가 마지막

	if (root == nullptr)
		return;

	cout << root->key << endl;
	PrintTree(root->left);
	PrintTree(root->right);
}

Node* BinarySearchTree::Search(Node* root, int key)
{
	return nullptr;
}

Node* BinarySearchTree::Min(Node* root)
{
	return nullptr;
}

Node* BinarySearchTree::Max(Node* root)
{
	return nullptr;
}

Node* BinarySearchTree::Previous(Node* node)
{
	return nullptr;
}

void BinarySearchTree::RePlace(Node* node1, Node* node2)
{
}

void BinarySearchTree::Delete(Node* node)
{
}
