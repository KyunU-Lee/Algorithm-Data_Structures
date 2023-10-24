#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;

long long fibo(int N) {
	if (N == 0) return 0;
	else if (N == 1) return 0;
	else if (N == 2) return 1;

	if (memo[N] != -1) {
		return memo[N];
	}

	return memo[N] = fibo(N - 1) + fibo(N - 2) + fibo(N - 3);
}


int main() {
	int N;
	cin >> N;

	memo.assign(N, -1);

	fibo(N-1);

	for (int i = 2; i < (int)memo.size(); ++i) {
		cout << "Fibo(" << i << ") : " << memo[i] << endl;
	}
}