#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
char grid[101][101];
bool visited[101][101] = { false };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int row, int col, char color) {
	queue<pair<int, int>> q;
	q.push({ row,col });
	visited[row][col] = true;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_row = cur_row + dx[i];
			int new_col = cur_col + dy[i];

			if (new_row < 1 || new_col < 1 || new_row > N || new_col > N) continue;
			if (visited[new_row][new_col] || grid[new_row][new_col] != color) continue;

			visited[new_row][new_col] = true;
			q.push({ new_row, new_col });
		}
	}
}

void bfs_color_weakness(int row, int col, char color) {
	queue<pair<int, int>> q;
	q.push({ row,col });
	visited[row][col] = true;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_row = cur_row + dx[i];
			int new_col = cur_col + dy[i];

			if (new_row < 1 || new_col < 1 || new_row > N || new_col > N) continue;
			if (visited[new_row][new_col]) continue;
			
			if ((color == 'R' || color == 'G') && (grid[new_row][new_col] == 'R' || grid[new_row][new_col] == 'G')) {
				visited[new_row][new_col] = true;
				q.push({ new_row, new_col });
			}
			else if (grid[new_row][new_col] == color) {
				visited[new_row][new_col] = true;
				q.push({ new_row, new_col });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cnt = 0;
	int color_weakness_cnt = 0;

	cin >> N;	
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				bfs(i, j, grid[i][j]);
				cnt++;
			} 
		}
	}

	fill(&visited[1][1], &visited[N + 1][0], false);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				bfs_color_weakness(i, j, grid[i][j]);
				color_weakness_cnt++;
			}
		}
	}

	cout << cnt << ' ' << color_weakness_cnt;

	return 0;
}