#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	int N, fst, num, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin >> fst;
		}
		else {
			cin >> num;
			pq.push(num);
		}
	}

	
	while (N != 1 && fst <= pq.top()) {
		int temp = pq.top();
		pq.pop();
		count++;
		fst++;
		pq.push(--temp);
	}

	cout << count;

	return 0;
}