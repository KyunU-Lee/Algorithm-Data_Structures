#include <iostream>
using namespace std;

int func(int N) {
	cout << "func(" << N << ") 호출함" << endl;

	if (N == 0) return 0;

	int result = N + func(N - 1);
	cout << N << "까지의 합 = " << result << endl;

	return result;
}

int main() {
	func(5);
}