#include <iostream>
#include <string>

using namespace std;

int main() {

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

}