#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v2;
vector<vector<int>> v(300, v2);


int sum(int i, int j, int x, int y) {
	int num = 0;

	for (int a = (i - 1); a < x; a++) {
		for (int b = (j - 1); b < y; b++) {
			num += v[a][b];
		}
	}

	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	

	int num;
	int n, m, k;
	int i, j, x, y;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			v[i].push_back(num);
		}
	}

	cin >> k;

	for (int p = 0; p < k; p++) {
		cin >> i >> j >> x >> y;
		cout << sum(i, j, x, y) << '\n';
	}

	return 0;
}