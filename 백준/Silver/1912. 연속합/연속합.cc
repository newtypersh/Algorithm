#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	
	int* arr = new int[num];
	int* dp = new int[num];
	

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int high = dp[0];

	for (int i = 1; i < num; i++) {
		dp[i] = max(dp[i-1]+arr[i],arr[i]);
		if (high < dp[i]) {
			high = dp[i];
		}
	}

	cout << high;

	delete[] arr;
	delete[] dp;
	

	return 0;
}