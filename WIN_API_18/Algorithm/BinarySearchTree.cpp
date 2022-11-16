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
	// �������
	if (root == nullptr)
		return root;

	// ���ϱ�
	if (root->key == key)
		return root;

	if (root->key > key)
	{
		return Search(root->left, key);
	}
	else
	{
		return Search(root->right, key);
	}
}

Node* BinarySearchTree::Min(Node* root)
{
	//if (root == nullptr)
	//	return root;

	//if (root->left == nullptr)
	//	return root;

	//return Min(root->left);

	if (root == nullptr)
		return nullptr;

	Node* node = root;
	while (true)
	{
		if (node->left == nullptr)
			return node;
		node = node->left;
	}
}

Node* BinarySearchTree::Max(Node* root)
{
	// ù ����ó��
	if (root == nullptr)
		return root;

	// ��������
	if (root->right == nullptr)
		return root;

	return Max(root->right);
}

Node* BinarySearchTree::Previous(Node* node)
{
	if (node == nullptr)
		return node;

	if (node->left != nullptr)
	{
		Node* prev = Max(node->left);
		if (prev == nullptr)
			return node->left;
		else
			return prev;
	}

	Node* parent = node->parent;

	while (parent != nullptr && node == parent->left)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BinarySearchTree::RePlace(Node* node1, Node* node2)
{
	// node1�� ��Ʈ����� ��
	if (node1->parent == nullptr)
		_root = node2;

	// node1�� �θ� �ʿ��� left�� �ִ� ���
	else if (node1 == node1->parent->left)
	{
		node1->parent->left = node2;
	}

	// node1�� �θ��ʿ��� right
	else
	{
		node1->parent->right = node2;
	}

	if (node2)
		node2->parent = node1->parent;

	delete node1;
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
		RePlace(node, node->right);
	else if (node->right == nullptr)
		RePlace(node, node->left);
	else
	{
		Node* prev = Previous(node);
		node->key = prev->key;
		Delete(prev);
	}
}
