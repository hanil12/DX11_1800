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

	// ���ο� ��� ���� �ڸ� ã��
	while (true)
	{
		// ���� ������ ���µ� ��尡 ���� ��
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
	// 3���� ��ȸ���
	// ������ȸ : ��Ʈ���� ��ȸ
	// ������ȸ : ���� �Ʒ����� ~ ��Ʈ ~ ������ �Ʒ�����
	// ������ȸ : ��Ʈ�� ������

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
