#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

bool BinarySearch(vector<int>& v, int num)
{
	int left = 0;
	int right = v.size() - 1;

	while (true)
	{
		if (left > right)
		{
			cout << "��ã�ҽ��ϴ�." << endl;
			return false;
		}

		cout << "Ž������ : " << left << " ���� " << right << "����" << endl;

		int mid = (left + right) / 2;

		if (num > v[mid])
		{
			cout << num << " > " << v[mid] << endl;
			left = mid + 1;
		}
		else if (num < v[mid])
		{
			cout << num << "<" << v[mid] << endl;
			right = mid - 1;
		}

		if (num == v[mid])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	// ���ĵǾ��ִ� t
	// left : 0, right : 9 / mid : 4 ... 14 < mid[4]
	// left : 0, right : 3 / mid : 1 ... 14 > mid[1]
	// left : 2, right : 3 / mid : 2 ... 14 < mid[2]
	// left : 2, right : 1
	vector<int> t = { 2,10,15,30, 56,80,90,120,150,200 };
	if (BinarySearch(t, 14))
	{
		cout << "ã�ҽ��ϴ�." << endl;
	}

	return 0;
}