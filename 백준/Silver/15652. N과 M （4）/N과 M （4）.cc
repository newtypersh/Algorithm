#include <iostream>
using namespace std;

int arr[9] = { 0, };
int N, M;

void dfs(int num, int depth) {
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++) {
		arr[depth + 1] = i;
		dfs(i, depth + 1);
	}
}

int main() {
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}