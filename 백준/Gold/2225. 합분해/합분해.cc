#include <iostream>
#include <vector>
using namespace std;

int dp[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= K; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	
	cout << dp[N][K];
	
	return 0;
}