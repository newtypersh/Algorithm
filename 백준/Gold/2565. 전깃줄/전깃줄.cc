#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	vector<int> dp(N, 1);

	int max_Length = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_Length = max(max_Length, dp[i]);
	}
	
	cout << N - max_Length << '\n';

	return 0;
}