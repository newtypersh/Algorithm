#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> university;

	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		university.push(v[i].second);
		if (university.size() > v[i].first) {
			university.pop();
		}
	}

	long long sum = 0;
	while (!university.empty()) {
		sum += university.top();
		university.pop();
	}

	cout << sum;

	return 0;
}