#include <iostream>

using namespace std;

bool issequence(int num){
	if (num < 100) {
		return true;
	}
	else if ((num>=100)&&(num<1000)) {
		int num3 = num / 100;
		int num2 = (num % 100) / 10;
		int num1 = num % 10;
		if ((num3 - num2) == (num2 - num1)) {
			return true;
		}
		else if ((num1 - num2) == (num2 - num3)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (issequence(i)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}