#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Interval;

bool cmp(const Interval& a, const Interval& b)
{
	return a.second < b.second;
}

class Chapter7
{
public:


	void Code7_1()
	{
		const vector<int> value = { 500, 100, 50, 10 };

		int X = 3550;

		vector<int> a = { 6,5,1,5 };

		int result = 0;

		for (int i = 0; i < 4; ++i)
		{
			int add = X / value[i];

			if (add > a[i]) add = a[i];

			X -= value[i] * add;
			result += add;
		}

		cout << "총 사용한 동전 개수 : " << result << endl;

	}

	void Code7_2()
	{
		vector<Interval> inter =
		{
			Interval(1,3),
			Interval(3,5),
			Interval(4,7),
			Interval(7,9),
			Interval(8,10)
		};

		int N = (int)inter.size();
		sort(inter.begin(), inter.end(), cmp);

		int result = 0;
		int current_end_time = 0;
		for (int i = 0; i < N; ++i)
		{
			if (inter[i].first < current_end_time)
				continue;
			++result;
			current_end_time = inter[i].second;			
		}
		cout << "Code7-2 : " << result << endl;
	}

	void Code7_3()
	{
		vector<int> A = { 10, 21, 13, 22, 15, 33 };
		vector<int> B = { 5, 25, 2, 37, 29, 60 };

		int N = A.size();
		int sum = 0;

		for (int i = N - 1; i >= 0; --i)
		{
			A[i] += sum;
			int amari = A[i] % B[i];
			int D = 0;
			if (amari != 0) D = B[i] - amari;
			sum += D;
		}
		cout << sum << endl;
	}



private:


};