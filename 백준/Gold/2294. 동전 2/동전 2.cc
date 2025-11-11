#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	vector<int> dp(k + 1, 987654321);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (coin[j] <= i && dp[i - coin[j]] != 987654321) {
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}

	cout << ((dp[k] == 987654321) ? -1: dp[k]);
	
	return 0;
}