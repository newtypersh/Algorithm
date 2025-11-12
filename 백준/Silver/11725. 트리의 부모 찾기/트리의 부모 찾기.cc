#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
int arr[MAX];
bool visited[MAX];
vector<int> tree[MAX];

void dfs(int k) {
	visited[k] = true;
	for (int i = 0; i < tree[k].size(); i++) {
		int next = tree[k][i];
		if (!visited[next]) {
			arr[next] = k;
			dfs(next);
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}