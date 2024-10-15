#pragma once
#include<iostream>

using namespace std;

class Chapter1
{
public: 
	/// <summary>
	/// 나이 맞히기 게임
	/// </summary>
	/// <param name="ageA">
	/// 나이 범이 최소
	/// </param>
	/// <param name="ageB">
	/// 나이 범위 최대
	/// </param>
	/// 
	/// <param name="resultAge">
	/// 정답 나이
	/// </param>
	/// <returns>
	/// 정답 나이가 리턴 되어야 함
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

