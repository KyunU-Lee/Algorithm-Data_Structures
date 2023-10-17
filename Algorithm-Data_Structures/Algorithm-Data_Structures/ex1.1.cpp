#include <iostream>
#include <vector>

using namespace std;

int main() {

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

}