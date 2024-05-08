#include "Chapter3.h"
#include <iostream>
#include <vector>

using namespace std;

void Chapter3::code3_1() {
	int N, v;
	cout << "길이 N 개중에서 v가 존재하는가?" << endl;
	cout << "N=";
	cin >> N;
	cout << "V=";
	cin >> v;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		cout << "a[" << i << "]";
		cin >> a[i];
		cout << endl;
	}

	bool exist = false;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] == v)
		{
			exist = true;
		}
	}
	
	if (exist)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

}

void Chapter3::code3_6()
{ 
	int N, W;
	cout << "데이터 개수=";
    cin >> N ;
	cout << "부분합 숫자=";
	cin >> W;

	vector<int> a(N);
	for (int i = 0; i < N; ++i)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}

	bool exist = false;
	for (int bit = 0; bit < (1 << N); ++bit)
	{
		int sum = 0;
		cout << "Bit=" << bit << endl;;
		for (int i = 0; i < N; ++i)
		{

			if (bit & (1 << i)) 
			{
				cout << "bit & (1 <<" <<i <<") = " << bit << " & " << (1 << i) << endl;
				sum += a[i];
			}
		}
		if (sum == W)
		{
			cout << "sum=" << sum;
			exist = true;
		}
	}

	if (exist)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;




}

/// <summary>
/// N개의 양의 정수 a..... 이 주어졌을 때 N 개의 정수가 모두 짝수라면 2로 나눈 값으로 치환하는
/// 작업을 더 이상 할 수 없을 때 까지 반복한다. 이런 작업을 몇 번 해야하는지 구하는 알고리즘을
/// 설계하라. 
/// </summary>
void Chapter3::ex3_5()
{
	//1 2 1 3 1 2 1 4 1 2 2 3 1 2 1
	vector<int> vec { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
	int count = 0;

	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		if (*iter % 2 == 0)
		{
			count++;
			cout << "count=" << count << endl;
			*iter = *iter / 2;
			iter = vec.begin();
		}
	}
	cout << endl;
	cout << "iterate count = " << count;
}

/// <summary>
/// 두 개의 양의 정수 K, N이 주어졌을 때 0 <= X, Y, Z <= K를 만족하는 정수 (X, Y, Z) 조합에서 
/// X + Y + Z = N 을 만족하는 경우가 얼마나 존재하는지 구하는 N^2 복잡도 알고리즘을 설계하라.
/// 
/// 해답 : https://betrue12.hateblo.jp/entry/2019/08/03/214940
/// </summary>
void Chapter3::ex3_6()
{
	int K = 15;
	int N = 20;

	int count = 0;

	for (int Z = 0; Z <= K; Z++)
	{
		for (int Y = 0; Y <= K; Y++)
		{
			int X = N - Y - Z;

			if (0 <= X && X <= K)
				count++;
		}
	}
	cout << "Count=" << count;
}
