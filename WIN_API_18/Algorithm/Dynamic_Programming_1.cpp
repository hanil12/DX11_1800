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
// - 메모이제이션, 캐시
// - 최적부분구조

// 피보나치 수열
// 캐싱
__int64 fAnswer[10000];

__int64 Fibonacci(int n)
{
	// 기저 사례
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// 메모이제이션
	if (fAnswer[n] != -1)
		return fAnswer[n];

	// 구하기
	fAnswer[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	return fAnswer[n];
}

vector<vector<int>> cache = vector<vector<int>>(46,vector<int>(46,-1));

int Combin(int n, int r)
{
	// 기저 사례
	if (r == 0 || n == r)
		return 1;

	// 캐시
	if (cache[n][r] != -1)
		return cache[n][r];

	// 구하기
	return cache[n][r] = Combin(n - 1, r - 1) + Combin(n - 1, r);
}

int main()
{
	memset(fAnswer, -1, 10000);

	cout << Fibonacci(100) << endl;

	cout << Combin(45, 6) << endl;

	return 0;
}