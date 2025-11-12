#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
int board[22][22];
vector<int> dice(6); // 위, 아래, 상, 하, 좌, 우

bool moveXY(int order) {
	int nx = x;
	int ny = y;
	switch (order) {
	case 1:
		ny++;
		break;
	case 2:
		ny--;
		break;
	case 3:
		nx--;
		break;
	case 4:
		nx++;
		break;
	}
	if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
		return false;
	}
	else {
		x = nx;
		y = ny;
		return true;
	}
}

void roll(int order) {
	vector<int> tmp = dice;

	if (order == 1) {		// 동
		dice[0] = tmp[4];
		dice[1] = tmp[5];
		dice[4] = tmp[1];
		dice[5] = tmp[0];
	}
	else if (order == 2) {	// 서
		dice[0] = tmp[5];
		dice[1] = tmp[4];
		dice[4] = tmp[0];
		dice[5] = tmp[1];
	}
	else if (order == 3) {	// 남
		dice[0] = tmp[3];
		dice[1] = tmp[2];
		dice[2] = tmp[0];
		dice[3] = tmp[1];
	}
	else {					// 북
		dice[0] = tmp[2];
		dice[1] = tmp[3];
		dice[2] = tmp[1];
		dice[3] = tmp[0];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int order;
	while (k--) {
		cin >> order;
		if (!moveXY(order)) continue;
		roll(order);
		if (board[x][y]) {
			dice[1] = board[x][y];
			board[x][y] = 0;
		}
		else {
			board[x][y] = dice[1];
		}
		cout << dice[0] << '\n';
	}

	return 0;
}