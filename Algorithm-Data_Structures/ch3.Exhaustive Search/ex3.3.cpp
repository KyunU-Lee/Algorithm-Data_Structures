#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, F = 10000000000, S = 10000000000;
	cout << "Vec SIze : ";
	cin >> N;

	vector<int> arr;
	cout << "Enter Number: ";
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		arr.push_back(A);
	}

	for (int i = 0; i < N; ++i) {
		if (arr[i] < F) {
			S = F;
			F = arr[i];
		}
		else if (arr[i] < S) S = arr[i];
	}

	cout << S << endl;

}