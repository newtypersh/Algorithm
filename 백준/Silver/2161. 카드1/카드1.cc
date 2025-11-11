#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		cout << q.front() << ' ';
		q.pop();
		int num = q.front();
		q.push(num);
		if (q.size() == 1) {
			break;
		}
		q.pop();
	}
	cout << q.front();

	return 0;
}