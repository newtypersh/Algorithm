#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;

int dx[8] = { -1, 1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };

void bfs(int row, int col, const vector<vector<int>>& graph, vector<vector<bool>>& visited) {
	queue<pair<int, int>> q;
	q.push({ row, col });
	visited[row][col] = true;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (!visited[ny][nx] && graph[ny][nx]) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		vector<vector<int>> graph(h, vector<int>(w));
		vector<vector<bool>> visited(h, vector<bool>(w));
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> graph[i][j];
			}
		}

		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && graph[i][j]) {
					bfs(i, j, graph, visited);
					count++;
				}
			}
		}
		cout << count << '\n';

	}
	

	return 0;
}