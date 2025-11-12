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
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	vector<int> dp(N, 1);
	vector<int> prev(N, -1);
	int max_length = 1;
	int last_index = 0;
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
				if (max_length < dp[i]) {
					max_length = dp[i];
					last_index = i;
				}
			}
		}
	}

	cout << max_length << '\n';

	vector<int> result;
	for (int i = last_index; i != -1; i = prev[i]) {
		result.push_back(num[i]);
	}
	reverse(result.begin(), result.end());

	for (int num : result) {
		cout << num << ' ';
	}
	cout << '\n';

	return 0;
}