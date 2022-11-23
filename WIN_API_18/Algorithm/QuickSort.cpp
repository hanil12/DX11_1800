#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// Quick Sort
// 기준(Pivot)을 정하고,
// 기준의 왼쪽을 무조건 나보다 작게
// 기준의 오른쪽은 무조건 나보다 크게

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

		// 역전되기 전이면 스왑
		if (lowIndex < highIndex)
			swap(v[lowIndex], v[highIndex]);
	}

	swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	// 기저 사례
	if (left > right)
		return;

	// 구하기
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