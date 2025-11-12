#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];

int main() {
	string str1, str2;
	int max_length = 0;
	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	str1 = " " + str1;
	str2 = " " + str2;
	
	int count = 0;
	// 16,000,000 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {	
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				max_length = max(max_length, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	cout << max_length;

	return 0;
}