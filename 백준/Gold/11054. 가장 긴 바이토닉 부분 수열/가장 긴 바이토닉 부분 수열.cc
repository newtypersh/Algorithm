#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N), asc(N, 1), desc(N, 1);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				asc[i] = max(asc[i], asc[j] + 1);
			}
		}
	}
	
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (A[i] > A[j]) {
				desc[i] = max(desc[i], desc[j] + 1);
			}
		}
	}

	int maxLength = 0;
	for (int i = 0; i < N; i++) {
		maxLength = max(maxLength, asc[i] + desc[i] - 1);
	}
	cout << maxLength << '\n';
	return 0;
}