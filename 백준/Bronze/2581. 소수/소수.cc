#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool isdecimal(int num) {
	if (num == 1) {
		return false;
	}
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num1, num2, total = 0, min=10000;
	cin >> num1 >> num2;

	for (int i = num1; i <= num2; i++) {
		if (isdecimal(i)) {
			total += i;
			if (i < min) {
				min = i;
			}
		}
	}

	if (total != 0) {
		cout << total << endl;
		cout << min;
	}
	else {
		cout << -1;
	}

    return 0;
}