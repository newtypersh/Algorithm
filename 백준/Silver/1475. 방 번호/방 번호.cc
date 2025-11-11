#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int count[10] = { 0 };
	cin >> n;

	while (n > 0) {
		if (n % 10 == 6) {
			if (count[6] > count[9]) {
				count[9]++;
			}
			else if (count[6] <= count[9]) {
				count[6]++;
			}
		}
		else if (n%10 == 9) {
			if (count[6] > count[9]) {
				count[9]++;
			}
			else if (count[6] <= count[9]) {
				count[6]++;
			}
		}
		else {
			count[(n % 10)] += 1;
		}
		n /= 10;
	}

	int max = 0;
	for (int i = 0; i <= 9; i++) {
		if (max < count[i]) {
			max = count[i];
		}
	}
	cout << max;

	return 0;
}
