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
}
