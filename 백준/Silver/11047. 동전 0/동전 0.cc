#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k >= p[i]) {
			count += (k / p[i]);
			k %= p[i];
		}
		if (k == 0)
			break;
	}
	cout << count;
	return 0;
}