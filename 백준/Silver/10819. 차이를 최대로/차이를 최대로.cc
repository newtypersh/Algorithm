#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A;

int calc() {
	int result = 0;
	for (int i = 0; i < N - 1; i++) {
		result += abs(A[i] - A[i + 1]);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	int result = 0;
	do {
		result = max(calc(), result);
	} while (next_permutation(A.begin(), A.end()));

	cout << result;

	return 0;
}