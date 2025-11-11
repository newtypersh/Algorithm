#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int count = 0;
	int num, n, m, ipt;
	cin >> num;
	for (int i = 0; i < num; i++) {
		count = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < n; j++) {
			cin >> ipt;
			q.push({ j, ipt }); // 값과 중요도를 push
			pq.push(ipt); // 우선 순위큐에 중요도를 push, 크기가 큰 순서대로 정렬됨
		}
		while (!q.empty()) {
			int index = q.front().first; // 값
			int value = q.front().second; // 중요도
			q.pop(); // queue를 pop
			if (pq.top() == value) { // 중요도가 우선순위 큐에서 제일 큰 값과 같다면
				pq.pop();
				++count;
				if (index == m) { // 값이 m(queue에서 몇번째에 놓여 있는지를 나타내는 정수)과 같다면
					cout << count << '\n';
					break;
				}
			}
			else {
				q.push({ index, value }); // 값과 중요도를 q에 push
			}
		}
	}
	

	return 0;
}