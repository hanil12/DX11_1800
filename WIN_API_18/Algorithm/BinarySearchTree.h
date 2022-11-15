#pragma once

struct Node
{
	Node() {}
	Node(int key) : key(key) {}

	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	int key = -1;
	int data = 0;
};

class BinarySearchTree
{
public:
	void Insert(int key);
	void PrintTree(Node* root);

	Node* Search(Node* root, int key);
	Node* Min(Node* root);
	Node* Max(Node* root);

	void Delete(Node* node);
	Node* Previous(Node* node);

	Node* _root = nullptr;
private:
	void RePlace(Node* node1, Node* node2);
};

