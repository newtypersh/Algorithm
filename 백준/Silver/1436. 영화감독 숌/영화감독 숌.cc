#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int countsix = 0;

	for (int i = 666; i <= 100000000; i++) {
		int num = i;
		while (num != 0) {
			if ((num % 10) == 6) {
				num /= 10;
				if ((num % 10) == 6) {
					num /= 10;
					if ((num % 10) == 6) {
						countsix++;
						break;
					}
				}
			}
			num /= 10;
		}
		if (countsix == n) {
			cout << i;
			break;
		}
	}

	return 0;
}