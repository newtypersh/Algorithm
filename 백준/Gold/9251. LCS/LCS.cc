#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	str1 = " " + str1;
	str2 = " " + str2;

	int n = str1.size();
	int m = str2.size();

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n - 1][m - 1];

	return 0;
}