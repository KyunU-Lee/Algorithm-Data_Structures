#include <iostream>
#include <vector>

using namespace std;

int main() {

	int age, ansCount = 0;
	cout << "나이 입력: ";
	cin >> age;

	int left = 0, right = 100;

	while (right - left > 1) {
		++ansCount;
		int mid = right - ((right - left) / 2);
		cout << "Age bigger then  " << mid << ": ";
		string ans;
		cin >> ans;
		if (ans == "Yes") left = mid;
		else right = mid;

	}

	cout << "your age : " << right << "Answer count : " << ansCount;
}