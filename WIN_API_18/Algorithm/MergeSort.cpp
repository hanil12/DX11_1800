#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// MergeSort
// 분할 정복(Divide And Conquer)
// - 분할 : 문제를 더 단순하게 분할한다.
// - 정복 : 문제를 해결한다.
// - 결합 : 결과를 취합하여 마무리한다.

// Quick Sort, Merge Sort
// 최악의 경우 : n^2
// 평균적으로 n x log2n;

// Partial Sort
// 최악의 경우 : n^2
// 평균적으로 n x log2n
// 만약 내가 m개 만큼만 정렬하겠다... n x log2m

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

	// 왼쪽이 먼저 끝남
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	// 오른쪽이 먼저 끝남
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

// 분할
// { 5,10,100,8,1,70,56,40 };
// { 5,10,100,8} {1,70,56,40}
// {5,10} {100,8}
// {5,10}

// {5,10} {8,100}
// {5,8,10,100}
// ... (정복)
// {5,8,10,100} {1,40,56,70} (결합)
// {1,5,8,10,40,56,70,100}
void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	// 분할
	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	// 정복, 결합
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 5,10,100,8,1,70,56,40 };
	//MergeSort(v, 0, 7);
	stable_sort(v.begin(), v.end());

	return 0;
}