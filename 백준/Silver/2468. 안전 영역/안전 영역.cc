#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[101][101];
bool visited[101][101] = { false };
bool wet[101][101] = { false };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int max_height = 0;
int max_count = 0;

void input();
void bfs(int row, int col);
void height_change(int height);
void search();

int main() {
	input();
	search();
	cout << max_count << endl;
	return 0;
}

void input() {
	cin >> N;
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			cin >> arr[row][col];
			max_height = max(max_height, arr[row][col]);
		}
	}
}
void bfs(int row, int col) {
	queue<pair<int, int>> q;
	q.push({ row, col });
	visited[row][col] = true;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_row = r + dy[i];
			int new_col = c + dx[i];
			if (new_row >= 101 || new_row < 1 || new_col >= 101 || new_col < 1) continue;
			if (!visited[new_row][new_col] && !wet[new_row][new_col]) {
				visited[new_row][new_col] = true;
				q.push({ new_row, new_col });
			}
		}
		
	}
}

void height_change(int height) {
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			visited[row][col] = false;
			wet[row][col] = false;
			if (arr[row][col] <= height) {
				wet[row][col] = true;
			}
		}
	}
}

void search() {
	for (int i = 0; i <= max_height; i++) {
		height_change(i);
		int count = 0;
		for (int row = 1; row <= N; row++) {
			for (int col = 1; col <= N; col++) {
				if (!visited[row][col] && !wet[row][col]) {
					bfs(row, col);
					count++;
				}
			}
		}
		max_count = max(max_count, count);
	}
}