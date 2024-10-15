#pragma once
#include<iostream>

using namespace std;

class Chapter1
{
public: 
	/// <summary>
	/// ���� ������ ����
	/// </summary>
	/// <param name="ageA">
	/// ���� ���� �ּ�
	/// </param>
	/// <param name="ageB">
	/// ���� ���� �ִ�
	/// </param>
	/// 
	/// <param name="resultAge">
	/// ���� ����
	/// </param>
	/// <returns>
	/// ���� ���̰� ���� �Ǿ�� ��
	/// </returns>
	void ex1_1(int ageA, int ageB, int resultAge)
	{
		int answer = -1;
		int count = 0;

		while (answer != resultAge)
		{
			count++;
			int mid = (ageA + ageB) / 2;
			if (mid > resultAge)
			{
				ageB = mid;
			}
			else if (mid < resultAge)
			{
				ageA = mid;
			}
			else
			{
				answer = mid;
			}
			
		}
		cout << "Your Age is :" << answer << "Count : " << count << endl;
	}

private:



};

