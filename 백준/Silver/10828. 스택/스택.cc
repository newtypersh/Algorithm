#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> v;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			v.push(num);
		}
		else if (str == "pop") {
			if (v.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << v.top() << "\n";
				v.pop();
			}
		}
		else if (str == "size") {
			cout << v.size() << "\n";
		}
		else if (str == "empty") {
			if (v.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (str == "top") {
			if (v.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << v.top() << "\n";
			}
		}
	}

	return 0;
}
