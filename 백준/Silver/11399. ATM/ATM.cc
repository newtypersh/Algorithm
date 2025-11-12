#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* p = new int[n];
	int* pp = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (p[j] > p[j + 1]) {
				int tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		pp[i] = 0;
		for (int j = 0; j <= i; j++) {
			pp[i] += p[j];
		}
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += pp[i];
	}
	cout << total;

	delete[] p;
	delete[] pp;
	p = nullptr;
	pp = nullptr;

	return 0;
}