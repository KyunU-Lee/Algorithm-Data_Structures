#include <iostream>
<<<<<<< HEAD
#include <string>
=======
#include <vector>
>>>>>>> d55d09d93bc444340b895304a9a521964ada0aa7

using namespace std;

int main() {

<<<<<<< HEAD
	int left = 20, right = 36, age;
	cout << "What your age :";
	cin >> age;

	while (right - left > 1)
	{
		int mid = right - ((right - left) / 2);

		string answer;

		cout << "Age Bigger then " << mid << "? Answer Yes / No : ";
		cin >> answer;

		if (answer == "Yes") left = mid;
		else right = mid;
	}

	cout << "Your age is " << right;
=======
	int age;
	cout << "나이 입력: ";
	cin >> age;

	int left = 20, right = 36;

	while (right - left > 1) {

		int mid = right - ((right - left) / 2);
		cout << "Age bigger then " << mid << ": ";
		string ans;
		cin >> ans;
		if (ans == "Yes") left = mid;
		else right = mid;

	}

	cout << "your age : " << right;
>>>>>>> d55d09d93bc444340b895304a9a521964ada0aa7

}