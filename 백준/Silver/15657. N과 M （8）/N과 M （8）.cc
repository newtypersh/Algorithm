#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8];
int arr[8];

void dfs(int start, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < N; i++) {
		arr[depth] = num[i];
		dfs(i, depth + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	dfs(0, 0);
	return 0;
}
