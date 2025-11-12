#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[8];
int arr[8];
bool check[8];


void dfs(int idx, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	int prev_num = 0;

	for (int i = idx; i < n; i++) {
		if (!check[i] && prev_num != num[i]) {
			arr[depth] = num[i];
			prev_num = arr[depth];
			check[i] = true;
			dfs(i + 1, depth + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	dfs(0, 0);

	return 0;
}