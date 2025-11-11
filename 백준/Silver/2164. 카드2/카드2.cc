#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<int> queue;
	int num;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		queue.push(i);
	}

	num = queue.front();
	queue.pop();

	while (!queue.empty()) {
		num = queue.front();
		queue.push(num);
		queue.pop();
		if (!queue.empty()) {
			queue.pop();
		}
	}

	cout << num;

	return 0;
}