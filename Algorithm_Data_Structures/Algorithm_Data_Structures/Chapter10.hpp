#pragma once

#include <iostream>
#include <vector>

using namespace std;





class Chapter10
{
public:
	struct Edge
	{
		int to; // 인접 꼭짓점 번호
		long long w; //가중치
		Edge(int to, long long w) : to(to), w(w) {}
	};

	using Graph = vector<vector<Edge>>;


	struct Heap
	{
		vector<int> heap;
		Heap() {}

		void push(int x)
		{
			heap.push_back(x); // 마지막에 삽입함 
			int i = (int)heap.size() - 1; //마지막 index 번호
			while (i > 0)
			{
				int p = (i - 1) / 2; // 부모 꼭짓점 번호
				if (heap[p] >= x) break;
				heap[i] = heap[p];
				i = p;
			}
			heap[i] = x;
		}

		int top()
		{
			if (!heap.empty()) return heap[0];
			else return -1;
		}

		void pop()
		{
			if (heap.empty()) return;
			int x = heap.back();
			heap.pop_back();
			int i = 0;
			while (i * 2 + 1 < (int)heap.size())
			{
				int child1 = i * 2 + 1, child2 = i * 2 + 2;
				if (child2 < (int)heap.size()
					&& heap[child2] > heap[child1])
				{
					child1 = child2;
				}
				if (heap[child1] <= x) break;
				heap[i] = heap[child1];
				i = child1;
			}
			heap[i] = x;
		}
	};

	void Code10_5()
	{
		Heap h;
		h.push(5), h.push(3), h.push(7), h.push(1);

		cout << h.top() << endl;
		h.pop();
		cout << h.top() << endl;
		h.push(11);
		cout << h.top() << endl;

	}




private:
	/// <summary>
	/// 무향 그래프
	/// </summary>
	vector<vector<int>> G ={{3,5,7}, {3,4,6},{4,5,7},{0,1,7},{1,2,6},{0,2},{1,4,7},{0,2,3,6}};

	/// <summary>
	/// 유향 그래프
	/// </summary>
	vector<vector<int>> dG = { {5},{3,6},{5,7},{0,7},{1,2,6},{},{7},{0},};

};
