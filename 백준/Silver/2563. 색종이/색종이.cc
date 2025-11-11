#include <iostream>

using namespace std;

int main() {
	int n, arr[100][100] = {0};
	int count = 0;
	int row = 0, col = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> row >> col;
		for (int j = (row - 1); j < (row + 9); j++) {
			for (int k = (col - 1); k < (col + 9); k++) {
				if ((j < 100) && (k < 100)) {
					if (arr[j][k] == 0) {
						arr[j][k] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				count++;
			}
		}
	}

	cout << count;

}