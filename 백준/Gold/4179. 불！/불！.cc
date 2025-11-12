#include <iostream>
#include <queue>

using namespace std;

int dx[8] = { 0,0,1,-1 };
int dy[8] = { 1,-1,0,0 };

queue<pair<int, int>> q;
queue<pair<int, int>> s;

char board[1001][1001];
int fire[1001][1001];
int jihun[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> r >> c;

	while (!q.empty()) {
		q.pop();
	}

	while (!s.empty()) {
		s.pop();
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];

			fire[i][j] = -1;
			jihun[i][j] = -1;

			if (board[i][j] == 'F') {
				q.push({ i,j });
				fire[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				s.push({ i,j });
				jihun[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {

		pair<int, int> current = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = current.first + dx[dir];
			int y = current.second + dy[dir];

			if (x < 0 || x >= r || y < 0 || y >= c) {
				continue;
			}
			if (fire[x][y] >= 0 || board[x][y] == '#') {
				continue;
			}
			fire[x][y] = fire[current.first][current.second] + 1;
			q.push({ x,y });
		}

	}

	while (!s.empty()) {
		pair<int, int> current = s.front();
		s.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = current.first + dx[dir];
			int y = current.second + dy[dir];

			if (x < 0 || x >= r || y < 0 || y >= c) {
				cout << jihun[current.first][current.second] + 1;
				return 0;
			}
			if (jihun[x][y] >= 0 || board[x][y] == '#') {
				continue;
			}
			if (fire[x][y] != -1 && jihun[current.first][current.second] + 1 >= fire[x][y]) {
				continue;
			}
			jihun[x][y] = jihun[current.first][current.second] + 1;
			s.push({ x,y });
		}
	}

	cout << "IMPOSSIBLE";
	
	return 0;
}
