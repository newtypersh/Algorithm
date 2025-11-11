#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, k, count = 0;

	cin >> num >> k;

	int i;

	for (i = 1; i <= num; i++) {
		if (num % i == 0) {
			count++;
			if (count == k) {
				break;
			}
		}
	}

	if (i > num) {
		cout << 0;
	}
	else {
		cout << i;
	}

    return 0;
}