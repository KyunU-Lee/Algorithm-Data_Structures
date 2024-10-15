#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


class Chapter6
{
public:
	void Code6_1()
	{
		const int N = 8;
		const vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39};

		cout << binary_search(5, a) << endl;
	}


	void Code6_3()
	{
		cout << "Start Game!" << endl;

		int left = 20, right = 36;

		while (right - left > 1)
		{
			int mid = left + (right - left) / 2;

			cout << "나이가 " << mid << "보다 작나요? '네', '아니오' 로 대답해주세요" << endl;

			string ans;

			cin >> ans;

			if (ans == "네")
				right = mid;
			else
				left = mid;
		}
		cout << "당신의 나이는 " << left << "입니다.";

	}

	void Code6_4()
	{
		vector<int> a = { 3, 5, 7 ,9, 11, 14 ,15, 19 };
		size_t N = a.size();
		vector<int> b = { 1, 2, 3, 4, 5, 6, 7 };
		size_t K = b.size();

		int min_value = INF;

		sort(b.begin(), b.end());
		b.push_back(INF);

		for (int i = 0; i < N; ++i)
		{
			auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

			int val = *iter;

			if (a[i] + val < min_value)
			{
				min_value = a[i] + val;
			}
		}
		cout << min_value << endl;
	}

	void Code6_5()
	{
		vector<long long> H = { 5, 12, 14, 21 };
		int N = H.size();
		vector<long long> S = { 6, 4, 7, 2 };

		// 상한 값
		long long M = 0;
		for (int i = 0; i < N; ++i)
		{
			M = max(M, H[i] + S[i] * N);
		}

		long long left = 0, right = M;

		while (right - left > 1)
		{
			long long mid = (left + right) / 2;

			bool ok = true;
			vector<long long> t(N, 0);	// 각 풍선이 터질 때까지의 제한 시간
			for (int i = 0; i < N; ++i)
			{
				if (mid < H[i]) ok = false;
				else
				{
					t[i] = (mid - H[i]) / S[i];
					cout << "t[" << i << "] : " << t[i] << endl;
				}
			}

			sort(t.begin(), t.end());

			for (int i = 0; i < N; ++i)
				if (t[i] < i)
					ok = false;

			if (ok) right = mid;
			else left = mid;
		}
		cout << right << endl;
	}


	void Ex6_1()
	{
		vector<int> a = { 12, 43, 7, 15, 9 };
		int N = a.size();
		vector<int> b = a;
		sort(b.begin(), b.end());

		vector<int> result;

		int left = 0, right = *(b.end() - 1);
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (a[i] == b[j])
				{
					result.push_back(j);
					break;
				}
			}
		}
		cout << "[";
		for (int i : result)
		{
			cout << i << ", ";
		}
		cout << "]" << endl;









	}




private:
	int binary_search(int key, const vector<int> &vec)
	{
		int left = 0; int right = (int)vec.size() - 1;
		while (right >= left)
		{
			int mid = left + (right - left) / 2;
			if (vec[mid] == key) return mid;
			else if (vec[mid] > key) right = mid - 1;
			else if (vec[mid] < key) left = mid + 1;
		}
		return -1;
	}



};