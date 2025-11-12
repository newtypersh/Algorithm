#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<int> queue;
	
	string str;
	int num;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			queue.push(num);
		}
		else if (str == "pop") {
			if (queue.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << queue.front() << '\n';
				queue.pop();
			}
		}
		else if (str == "size") {
			cout << queue.size() << '\n';
		}
		else if (str == "empty") {
			if (queue.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "front") {
			if (queue.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << queue.front() << '\n';
			}
		}
		else if (str == "back") {
			if (queue.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << queue.back() << '\n';
			}
		}
	}
	

	return 0;
}