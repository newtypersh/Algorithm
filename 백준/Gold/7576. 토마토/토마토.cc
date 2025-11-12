#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int box[1000][1000] = { 0 };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	while (!q.empty()) {
		q.pop();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = current.first+ dx[dir];
			int y = current.second + dy[dir];

			if ((x>=0)&&(x<n)&&(y>=0)&&(y<m)) {
				if (box[x][y] == 0) {
					box[x][y] = box[current.first][current.second] + 1;
					q.push({ x,y });
				}
			}
		}
	}

	int max = 0;
	bool impossible = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				impossible = true;
				break;
			}
			if (max < box[i][j]) {
				max = box[i][j];
			}
		}
		if (impossible) {
			break;
		}
	}

	if (!impossible) {
		cout << max-1;
	}




	return 0;
}