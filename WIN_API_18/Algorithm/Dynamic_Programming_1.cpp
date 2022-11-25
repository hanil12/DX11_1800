#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

// DP
// - �޸������̼�, ĳ��
// - �����κб���

// �Ǻ���ġ ����
// ĳ��
__int64 fAnswer[10000];

__int64 Fibonacci(int n)
{
	// ���� ���
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// �޸������̼�
	if (fAnswer[n] != -1)
		return fAnswer[n];

	// ���ϱ�
	fAnswer[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	return fAnswer[n];
}

vector<vector<int>> cache = vector<vector<int>>(46,vector<int>(46,-1));

int Combin(int n, int r)
{
	// ���� ���
	if (r == 0 || n == r)
		return 1;

	// ĳ��
	if (cache[n][r] != -1)
		return cache[n][r];

	// ���ϱ�
	return cache[n][r] = Combin(n - 1, r - 1) + Combin(n - 1, r);
}

int main()
{
	memset(fAnswer, -1, 10000);

	cout << Fibonacci(100) << endl;

	cout << Combin(45, 6) << endl;

	return 0;
}