#include "Chapter3.h"
#include <iostream>
#include <vector>

using namespace std;

void Chapter3::code3_1() {
	int N, v;
	cout << "���� N ���߿��� v�� �����ϴ°�?" << endl;
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
	cout << "������ ����=";
    cin >> N ;
	cout << "�κ��� ����=";
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
/// N���� ���� ���� a..... �� �־����� �� N ���� ������ ��� ¦����� 2�� ���� ������ ġȯ�ϴ�
/// �۾��� �� �̻� �� �� ���� �� ���� �ݺ��Ѵ�. �̷� �۾��� �� �� �ؾ��ϴ��� ���ϴ� �˰�����
/// �����϶�. 
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
/// �� ���� ���� ���� K, N�� �־����� �� 0 <= X, Y, Z <= K�� �����ϴ� ���� (X, Y, Z) ���տ��� 
/// X + Y + Z = N �� �����ϴ� ��찡 �󸶳� �����ϴ��� ���ϴ� N^2 ���⵵ �˰����� �����϶�.
/// 
/// �ش� : https://betrue12.hateblo.jp/entry/2019/08/03/214940
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
