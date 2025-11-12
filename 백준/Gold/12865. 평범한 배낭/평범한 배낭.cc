#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v;
int N, K;

int calc() {
	vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (v[i].first <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

			
		}
	}
	return dp[N][K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {		
		cin >> v[i].first >> v[i].second;
	}
	cout << calc(); 

	return 0;
}