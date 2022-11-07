#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Stack, Queue

// Stack
// : 팬케이크 굽고 먹기 : First Input Last Out -> FILO, LIFO

// Queue
// : 줄서기 : First Input First Out -> FIFO, LILO

struct Player
{
public:
	Player(int n) { cout << "생성자 호출" << endl; }
	Player(const Player& p) { cout << "복사생성자" << endl; }
	Player(Player&& p) { cout << "이동생성자" << endl; }
	~Player() { cout << "소멸자 호출" << endl; }
};

class Stack
{
public:
	void push(const int& value)
	{
		v.push_back(value);
	}

	void pop()
	{
		v.pop_back();
	}

	const int& top()
	{
		return v.back();
	}

	bool empty()
	{
		return v.size() == 0;
	}

public:
	vector<int> v;
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (true)
	{
		if (s.empty() == true)
			break;

		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}