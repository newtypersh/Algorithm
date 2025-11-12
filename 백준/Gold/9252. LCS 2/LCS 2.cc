#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s1, s2;
	cin >> s1 >> s2;

	s1 = " " + s1;
	s2 = " " + s2;

	int n = s1.length();
	int m = s2.length();


	vector<pair<int, int>> prev;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	
	cout << dp[n - 1][m - 1] << '\n';
	

	int num1 = n - 1;
	int num2 = m - 1;
	vector<char> v;
	while (num1 != 0 || num2 != 0) {
		if (dp[num1 - 1][num2] == dp[num1][num2]) {
			num1 -= 1;
		}
		else if (dp[num1][num2 - 1] == dp[num1][num2]) {
			num2 -= 1;
		}
		else {
			v.push_back(s1[num1]);
			num1 -= 1;
			num2 -= 1;
		}

		if (dp[num1][num2] == 0) {
			break;
		}
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	
	

	return 0;
}