#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;
int v[100][100][100];
queue <tuple<int, int, int>> q;
bool visited[100][100][100] = { false, };
int depth[100][100][100] = { 0, };
int max_value = 0;

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

void bfs() {
	while (!q.empty()) {
		int zz = get<0>(q.front());
		int yy = get<1>(q.front());
		int xx = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = zz + dz[i];
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
			if (visited[nz][ny][nx] || v[nz][ny][nx] == -1) continue;
			depth[nz][ny][nx] = depth[zz][yy][xx] + 1;
			max_value = max(max_value, depth[nz][ny][nx]);
			v[nz][ny][nx] = 1;
			q.push({ nz, ny, nx });
			visited[nz][ny][nx] = true;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> M >> N >> H;

	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> v[i][j][k];
				if (v[i][j][k] == 1) {
					q.push({ i, j, k });
					visited[i][j][k] = true;
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (v[i][j][k] == 0) {
					max_value = -1;
					break;
				}
			}
		}
	}

	cout << max_value;

	return 0;
}