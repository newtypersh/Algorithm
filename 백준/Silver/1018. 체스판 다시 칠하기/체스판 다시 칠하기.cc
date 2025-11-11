#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char copy_arr[8][8];
char board[50][50];

int count_number() {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && copy_arr[i][j] != 'W') {
					cnt1++;
				}
				else if (j % 2 == 1 && copy_arr[i][j] != 'B') {
					cnt1++;
				}
			}
			else {
				if (j % 2 == 0 && copy_arr[i][j] != 'B') {
					cnt1++;
				}
				else if (j % 2 == 1 && copy_arr[i][j] != 'W') {
					cnt1++;
				}

			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && copy_arr[i][j] != 'B') {
					cnt2++;
				}
				else if (j % 2 == 1 && copy_arr[i][j] != 'W') {
					cnt2++;
				}
			}
			else {
				if (j % 2 == 0 && copy_arr[i][j] != 'W') {
					cnt2++;
				}
				else if (j % 2 == 1 && copy_arr[i][j] != 'B') {
					cnt2++;
				}

			}
		}
	}
	return min(cnt1, cnt2);
}

void CopyArr(int s1, int s2) {
	for (int i = s1; i < s1 + 8; i++) {
		for (int j = s2; j < s2 + 8; j++) {
			copy_arr[i-s1][j-s2] = board[i][j];
		}
	}
}

int main() {
	int minimum = 10000000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			CopyArr(i, j);
			minimum = min(minimum, count_number());
		}
	}

	cout << minimum;
}