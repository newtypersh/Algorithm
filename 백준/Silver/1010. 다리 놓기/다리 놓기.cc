#include <iostream>

using namespace std;

int save[30][30];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int n,m;

	for (int i = 1; i < 30; i++) {
		save[1][i] = i;
		save[i][i] = 1;
	}
	for (int i = 2; i < 30;i++) {
		for (int j = i+1; j < 30;j++) {
			for (int k = i-1; k < j; k++) {
				save[i][j] += save[i - 1][k];
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << save[n][m] << '\n';
	}


	return 0;
}