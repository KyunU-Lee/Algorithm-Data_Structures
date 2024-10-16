#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Node
{
	Node* next, * prev;
	string name;
	Node(string name_ = "") : next(NULL), prev(NULL), name(name_) {}
};

Node* nil;


class Chapter8
{
public:
	void Code8_4()
	{
		init();
		for (int i = 0; i < (int)names.size(); ++i)
		{
			Node* node = new Node(names[i]);

			insert(node);

			cout << "cur step" << i << ": ";
			printlist();
		}
	}

	void Code8_5()
	{
		init();

		Node* myongjin{};
		for (int i = 0; i < (int)names.size(); ++i)
		{
			Node* node = new Node(names[i]);

			insert(node);

			if (names[i] == "myongjin") myongjin = node;
		}

		cout << "Before : ";
		printlist();
		erase(myongjin);
		cout << "After : ";
		printlist();
	}


private:
	vector<string> names =
	{
		"bakho",
		"myongjin",
		"rangi",
		"daeho",
		"nara",
		"gildong"
	};

	void init()
	{
		nil = new Node();
		nil->next = nil;
		nil->prev = nil;
	}

	void printlist()
	{
		Node* cur = nil->next;
		for (; cur != nil; cur = cur->next)
		{
			cout << cur->name << " -> ";
		}
		cout << endl;
	}

	void insert(Node* v, Node* p = nil)
	{
		v->next = p->next;
		p->next->prev = v;
		p->next = v;
		v->prev = p;
	}

	void erase(Node* v)
	{
		if (v == nil) return;
		v->prev->next = v->next;
		v->next->prev = v->prev;
		delete v;
	}


};