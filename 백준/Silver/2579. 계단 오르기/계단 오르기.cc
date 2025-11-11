#include <iostream>

using namespace std;

int dp[301] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	int stair[301] = { 0 };
	for (int i = 1; i <= num; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2]+stair[3]);

	for (int i = 4; i <= num; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[num] << '\n';

	

	return 0;
}