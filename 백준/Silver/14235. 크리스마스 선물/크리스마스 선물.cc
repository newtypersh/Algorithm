#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	int n, a, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			for(int j = 0; j < a; j++) {
				cin >> num;
				pq.push(num);
			}
		}
	}
	return 0;
}