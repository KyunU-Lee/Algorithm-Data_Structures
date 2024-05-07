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
