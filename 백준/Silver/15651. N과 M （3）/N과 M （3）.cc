#include <iostream>
using namespace std;

int arr[8] = { 0, };
int N, M;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[depth + 1] = i;
		dfs(depth + 1);
	}
}

int main() {
	cin >> N >> M;
	dfs(0);
	return 0;
}