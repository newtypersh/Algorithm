#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
vector<vector<char>> v;
vector<vector<bool>> visited;
vector<pair<int, int>> land;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result = 0;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

void bfs(int x, int y) {
	visited.assign(N, vector<bool>(M, false));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple( x, y, 0 ));
	visited[x][y] = true;

	while (!q.empty()) {
		int tx = get<0>(q.front());
		int ty = get<1>(q.front());
		int length = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (OOB(nx, ny) || visited[nx][ny] == true || v[nx][ny] == 'W') continue;
			visited[nx][ny] = true;
			q.push(make_tuple( nx, ny, length + 1 ));
			result = max(result, (length + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	v.resize(N, vector<char>(M));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'L') {
				land.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < land.size(); i++) {
		int x = land[i].first;
		int y = land[i].second;
		bfs(x, y);
	}

	cout << result;

	return 0;
}