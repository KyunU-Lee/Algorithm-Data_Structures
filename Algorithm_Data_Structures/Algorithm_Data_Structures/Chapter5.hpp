#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 60;

const int INTF = 1 << 29;

class Chapter5
{
public:
//N =7, H = {2,9,4,5,1,6,10};
	void Code5_1()
	{
		vector<int> h = { 2,9,4,5,1,6,10 };
		vector<long long> dp(h.size(), INF);
		size_t N = h.size();

		dp[0] = 0;

		for (int i = 1; i < N; i++)
		{
			if (i == 1) dp[i] = abs(h[i] - h[i - 1]);
			else dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));

		}
		cout << "Code5_1 : " << dp[N - 1] << endl;
	}

	void Code5_3()
	{
		vector<int> h = { 2,9,4,5,1,6,10 };
		size_t N = h.size();
		vector<long long> dp(N, INF);

		dp[0] = 0;

		for (int i = 1; i < N; ++i)
		{
			chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
			if (i > 1)
				chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
		}
		cout << "Code5_3 : " << dp[N - 1] << endl;
	}

	void Code5_4()
	{
		vector<int> h = { 2,9,4,5,1,6,10 };
		size_t N = h.size();
		vector<long long> dp(N, INF);
		dp[0] = 0;

		for (int i = 0; i < N; ++i)
		{
			if (i + 1 < N)
				chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
			if (i + 2 < N)
				chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
		}
		cout << "Code5_4 : " << dp[N - 1] << endl;
	}

	void Code5_7()
	{

		vector<long long> weight = { 0,1,2,3,4,5,6};
		int N = weight.size();

		vector<long long> value = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		long long W = value.size();


		vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));


		for (int i = 0; i < N; ++i)
		{
			for (int w = 0; w <= W; ++w)
			{
				if (w - weight[i] >= 0)
				{
					chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
				}
				chmax(dp[i + 1][w], dp[i][w]);
			}
		}
		cout << "Code5_7: " << dp[N][W] << endl;
	}

	void Code5_8()
	{
		string S = "algorithm";
		string T = "logistic";

		vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INTF));

		dp[0][0] = 0;

		for (int i = 0; i <= S.size(); ++i)
		{
			for (int j = 0; j <= T.size(); ++j)
			{
				// 대체
				if (i > 0 && j > 0)
				{
					if (S[i - 1] == T[j - 1]) 
						chmin(dp[i][j], dp[i - 1][j - 1]);
					else 
						chmin(dp[i][j], dp[i - 1][j - 1] + 1);
				}
				// 삭제
				if (i > 0) 
					chmin(dp[i][j], dp[i - 1][j] + 1);
				// 삽입
				if (j > 0) 
					chmin(dp[i][j], dp[i][j - 1] + 1);
			}
		}
		cout << "Code5_8 : " << dp[S.size()][T.size()] << endl;
	}

	void Code5_9()
	{
		int N;
		cin >> N;
		vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> c[i][j];
			}
		}

		vector<long long> dp(N + 1, INF);

		dp[0] = 0;

		for (int i = 0; i <= N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				chmin(dp[i], c[j][i]);
			}
		}
	}

	void Ex5_1()
	{
		// 여름 방학 날짜 수
		int N = 3;
		vector<vector<int>> day
		{
			{10, 40, 70},
			{20, 50, 80},
			{30, 60, 90}
		};


		vector<vector<int>> dp(N + 1, vector<int>(3, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					if (j == k) continue;
					chmax(dp[i + 1][k], dp[i][j] + day[i][k]);
				}
			}
		}
		int result = 0;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << dp[i][j] << " ,";
			}
			cout << endl;
		}

	}

	void Ex5_2()
	{
		vector<int> a = { 1,2,3,4,5,6,7,8,9 };
		size_t N = a.size();
		// 총합 
		int W = 45;

		vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
		dp[0][0] = true;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= W; ++j)
			{
				if (dp[i][j]) dp[i + 1][j] = true;

				if (j >= a[i] && dp[i][j - a[i]]) dp[i + 1][j] = true;
			}
		}
		if (dp[N][W]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	void Ex5_3()
	{
		vector<int> a = { 1,2,3,4,5,6,7,8,9 };
		size_t N = a.size();

		int W = 10000;
		vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
		dp[0][0] = true;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; i <= W; ++i)
			{
				if (!dp[i][j]) continue;
				dp[i + 1][j] = true;
			}
		}



	}













private:
	/// <summary>
	/// Code5_2 완화를 위한 함수 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	template<class T> void chmin(T& a, T b)
	{
		if (a > b) a = b;
	}

	template<class T> void chmax(T& a, T b)
	{
		if (a < b) a = b;
	}

};