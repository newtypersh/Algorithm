#include <iostream>
using namespace std;

int N, max_num = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char board[50][50];

void count_max_line() {
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
			}
			else {
				max_num = max(max_num, cnt);
				cnt = 1;
			}
		}
		max_num = max(max_num, cnt);
	}

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
			}
			else {
				max_num = max(max_num, cnt);
				cnt = 1;
			}
		}
		max_num = max(max_num, cnt);
	}
}

void Bomboni() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (board[i][j] != board[ny][nx] && nx >=0 && ny >= 0 && nx < N && ny < N) {
					int temp = board[i][j];
					board[i][j] = board[ny][nx];
					board[ny][nx] = temp;
					count_max_line();
					temp = board[i][j];
					board[i][j] = board[ny][nx];
					board[ny][nx] = temp;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	Bomboni();
	cout << max_num;
	return 0;
}