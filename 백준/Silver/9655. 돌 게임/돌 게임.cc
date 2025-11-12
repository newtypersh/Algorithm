#include <iostream>

using namespace std;


void DP(string name, int n) {
	if (n == 1) {
		if (name == "SK") {
			cout << "SK";
			return;
		}
		else {
			cout << "CY";
			return;
		}
	}
	else if (n < 3 && n > 1) {
		if (name == "SK") {
			return DP("CY", n - 1);
		}
		else {
			return DP("SK", n - 1);
		}
		
	}
	else if (n == 3) {
		if (name == "SK") {
			cout << "SK";
			return;
		}
		else {
			cout << "CY";
			return;
		}
	}
	else {
		if (name == "SK") {
			return DP("CY", n - 3);
		}
		else {
			return DP("SK", n - 3);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	DP("SK", n);

	return 0;
}