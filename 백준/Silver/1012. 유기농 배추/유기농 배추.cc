#include <iostream>
#include <queue>
using namespace std;

int graph[50][50];
bool visited[50][50];
int x_dir[4] = { -1, 1, 0, 0 };
int y_dir[4] = { 0, 0, -1, 1 };
int cnt;

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + x_dir[i];
			int next_y = cur_y + y_dir[i];
			if (next_x >= 0 && next_x <= 49 && next_y >= 0 && next_y <= 49 && !visited[next_x][next_y] && graph[next_x][next_y] == 1) {
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}
}

int main() {
	int t, m, n, k, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			graph[x][y] = 1;
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[j][k] && graph[j][k] == 1) {
					bfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				graph[j][k] = 0;
				visited[j][k] = false;
			}
		}
	}

	return 0;
}