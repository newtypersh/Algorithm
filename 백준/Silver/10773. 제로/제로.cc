#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> stack;

	int sum = 0;
	int num;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> num;
		if (num == 0) {
			stack.pop();
		}
		else {
			stack.push(num);
		}
	}

	while (!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}

	cout << sum;

	return 0;
}