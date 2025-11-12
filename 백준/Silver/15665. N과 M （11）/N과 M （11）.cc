#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[7];
int arr[7];

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev_num = 0;
	for (int i = 0; i < N; i++) {
		if (prev_num != num[i]) {
			arr[depth] = num[i];
			prev_num = num[i];
			dfs(depth + 1);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	dfs(0);
	return 0;
}