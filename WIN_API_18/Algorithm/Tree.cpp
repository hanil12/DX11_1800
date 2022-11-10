#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

// Ʈ��
// �θ� - �ڽİ���
// �ֻ��� �θ� : root (node)
// ������ �ڽ� : leaf (node)
// ���� : ��Ʈ���� ������ �Ÿ�
// ���� : �ִ� ����

// ������������ ��Ÿ���µ� ����.
// Ʈ���� �߶� Ʈ�� (����� �Ӽ��� ���� �ִ�.)

struct Node
{
	Node() {}
	Node(const string& data) : _data(data) {}

	string _data;
	vector<Node*> _children;
};

Node* CreateTree()
{
	Node* root = new Node("������");
	{
		Node* node1 = new Node("���α׷�����");
		root->_children.push_back(node1);
		{
			Node* leaf1 = new Node("����");
			node1->_children.push_back(leaf1);

			Node* leaf2 = new Node("Ŭ��");
			node1->_children.push_back(leaf2);

			Node* leaf3 = new Node("����");
			node1->_children.push_back(leaf3);
		}

		Node* node2 = new Node("��ȹ��");
		root->_children.push_back(node2);
		{
			Node* leaf1 = new Node("����������");
			node2->_children.push_back(leaf1);

			Node* leaf2 = new Node("�뷱��");
			node2->_children.push_back(leaf2);

			Node* leaf3 = new Node("���丮");
			node2->_children.push_back(leaf3);
		}

		Node* node3 = new Node("��Ʈ��");
		root->_children.push_back(node3);
		{
			Node* leaf1 = new Node("��ȭ");
			node3->_children.push_back(leaf1);

			Node* leaf2 = new Node("���");
			node3->_children.push_back(leaf2);

			Node* leaf3 = new Node("��");
			node3->_children.push_back(leaf3);
		}
	}

	return root;
}

void PrintTree(Node* root, int deepth)
{
	for (int i = 0; i < deepth; i++)
	{
		cout << "-";
	}

	cout << root->_data << endl;

	for (auto& node : root->_children)
	{
		PrintTree(node, deepth + 1);
	}
}

int main()
{
	Node* root = CreateTree();
	// PrintTree(root, 0);

	return 0;
}