#include <iostream>

using namespace std;

int dp[11] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int j = 4; j < 11; j++) {
		dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << dp[num] << endl;
	}

	return 0;
}