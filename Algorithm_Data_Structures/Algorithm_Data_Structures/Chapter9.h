#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Chapter9
{
public:

	void Code9_1()
	{
		stinit();

		stpush(3);
		stpush(5);
		stpush(7);

		cout << stpop() << endl;
		cout << stpop() << endl;

		stpush(9);
	}

	void Code9_2()
	{
		quinti();

		enqueue(3);
		enqueue(5);
		enqueue(7);

		cout << dequeue() << endl;
		cout << dequeue() << endl;
		cout << dequeue() << endl;
	}



private:
	const int MAX = 100000;
	int st[100000];
	int top = 0;

	void stinit()
	{
		top = 0;
	}

	bool stisEmpty()
	{
		return (top == 0);
	}

	bool stisFull()
	{
		return (top == MAX);
	}

	void stpush(int x)
	{
		if (stisFull())
		{
			cout << "Error: stack is full." << endl;
			return;
		}
		st[top] = x;
		++top;
	}

	int stpop()
	{
		if (stisEmpty())
		{
			cout << "Error : Stack is empty." << endl;
		}
		--top;
		return st[top];
	}

	int qu[100000];
	int tail = 0, head = 0;

	void quinti()
	{
		head = tail = 0;
	}

	bool quisEmpty()
	{
		return (head == tail);
	}

	bool quisFull()
	{
		return (head == (tail + 1) % MAX);
	}

	void enqueue(int x)
	{
		if (quisFull())
		{
			cout << "Error: Queue is full." << endl;
			return;
		}

		qu[tail] = x;
		++tail;
		// 링버퍼 끝에 도달하면 0
		if (tail == MAX) tail = 0;
	}

	int dequeue()
	{
		if (quisEmpty())
		{
			cout << "Error: Queue is empty." << endl;
			return -1; 
		}
		int result = qu[head];
		++head;
		if (head == MAX) head = 0;
		return result;
	}


};

