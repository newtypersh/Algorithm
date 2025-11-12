#include <iostream>
#include <vector>
using namespace std;

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	
	dp[1] = v[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + v[j]);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}