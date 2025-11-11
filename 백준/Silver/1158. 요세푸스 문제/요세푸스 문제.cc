#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	queue<int> q;
	int n, k, cnt=0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << '<';
	while (q.size() != 1) {
		cnt++;
		int num = q.front();
		q.pop();
		if (cnt % k != 0) {
			q.push(num);
		}
		else {
			cout << num;
			cout << ", ";
		}
	}
	
	cout << q.front() <<'>';

	return 0;
}