#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// Quick Sort
// ����(Pivot)�� ���ϰ�,
// ������ ������ ������ ������ �۰�
// ������ �������� ������ ������ ũ��

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex)
			break;

		while (lowIndex <= right && pivot >= v[lowIndex])
			lowIndex++;

		while (highIndex >= left && pivot <= v[highIndex])
			highIndex--;

		// �����Ǳ� ���̸� ����
		if (lowIndex < highIndex)
			swap(v[lowIndex], v[highIndex]);
	}

	swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// ���� ���
	if (left > right)
		return;

	// ���ϱ�
	int pivotIndex = Partition(v, left, right);
	cout << left << " ~ " << pivotIndex - 1 << endl;
	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex + 1, right);
}

int main()
{
	vector<int> v = { 5,10,100,10,1,70,56,40 };
	QuickSort(v, 0, 7);

	// std::stable_sort()

	return 0;
}