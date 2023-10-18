#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, V;
	cout << "Enter Size : ";
	cin >> N;
	cout << "Enter V : ";
	cin >> V;
	vector<int> arr;
	cout << "Enter Number : ";
	for (int i = 0; i < N; ++i) {
		cin >> M;
		arr.push_back(M);
	}

	int count = 0;
	for (int i = 0; i < N; ++i) {
		cout << "arr[i] : " << arr[i] << endl;
		if (arr[i] == V) ++count;
	}

	cout << "Count : " << count;

}