#include <iostream>
#include <vector>
#define INF 1000000001
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;

	vector<long long> distance(N);
	vector<long long> liter_won(N + 1);
	vector<long long> result(N + 1);


	for (int i = 1; i <= N - 1; i++) {
		cin >> distance[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> liter_won[i];
	}

	long long min_value = INF;
	for (int i = 1; i <= N - 1; i++) {
		min_value = min(min_value, liter_won[i]);
		result[i + 1] = result[i] + (min_value * distance[i]);
	}

	cout << result[N];

	return 0;
}