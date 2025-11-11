#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	int* p = new int[n+1] {0};
	
	p[0] = 1;
	if (n >= 1) {
		p[1] = 1;
	}
	if (n >= 2) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (p[i] == 0) {
				for (int j = i + i; j <= n; j += i) {
					p[j] = 1;
				}
			}
		}
	}
	
	for (int i = m; i <= n; i++) {
		if (p[i] == 0)
			cout << i << "\n";
	}

	delete[] p;
	p = nullptr;
	
	return 0;
}