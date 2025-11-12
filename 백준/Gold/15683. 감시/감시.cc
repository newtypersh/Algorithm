#include <iostream>
#include <vector>
#include <cmath>
#define MAX 99999999
using namespace std;

int N, M;
vector<vector<int>> v1;
vector<vector<int>> v2;
vector<pair<int, int>> cctv;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int result = MAX;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

void upd(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || v2[x][y] == 6) return;
		if (v2[x][y] != 0) continue;
		v2[x][y] = 7;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	v1.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v1[i][j];
			if (v1[i][j] != 0 && v1[i][j] != 6) {
				cctv.push_back({ i, j });
			}
		}
	}

	for (int tmp = 0; tmp < pow(4, cctv.size()); tmp++) {
		v2 = v1;

		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;

			if (v1[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (v1[x][y] == 2) {
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (v1[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (v1[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else if (v1[x][y] == 5) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		}

		int val = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v2[i][j] == 0) val++;
			}
		}
		result = min(result, val);
	}
	cout << result;

	return 0;
}