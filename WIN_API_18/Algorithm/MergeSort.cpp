#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// MergeSort
// ���� ����(Divide And Conquer)
// - ���� : ������ �� �ܼ��ϰ� �����Ѵ�.
// - ���� : ������ �ذ��Ѵ�.
// - ���� : ����� �����Ͽ� �������Ѵ�.

// Quick Sort, Merge Sort
// �־��� ��� : n^2
// ��������� n x log2n;

// Partial Sort
// �־��� ��� : n^2
// ��������� n x log2n
// ���� ���� m�� ��ŭ�� �����ϰڴ�... n x log2m

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// {5, 10}
	int leftIndex = left; // 0
	int rightIndex = mid + 1; // 1
	// left	 0
	// mid	 0
	// right 1

	vector<int> temp;

	while (leftIndex <= mid && rightIndex <= right)
	{
		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	// ������ ���� ����
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	// �������� ���� ����
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

// ����
// { 5,10,100,8,1,70,56,40 };
// { 5,10,100,8} {1,70,56,40}
// {5,10} {100,8}
// {5,10}

// {5,10} {8,100}
// {5,8,10,100}
// ... (����)
// {5,8,10,100} {1,40,56,70} (����)
// {1,5,8,10,40,56,70,100}
void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	// ����
	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	// ����, ����
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 5,10,100,8,1,70,56,40 };
	//MergeSort(v, 0, 7);
	stable_sort(v.begin(), v.end());

	return 0;
}