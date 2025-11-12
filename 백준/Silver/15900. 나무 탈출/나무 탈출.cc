#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[500001];
bool visitnode[500001];
int cnt = 0;

void dfs(int s, int depth) {
	if (s != 1 && tree[s].size() == 1) {
		cnt+=depth;
		return;
	}
	for (int i = 0; i < tree[s].size(); i++) {
		if (!visitnode[tree[s][i]]) {
			visitnode[tree[s][i]] = true;
			dfs(tree[s][i], depth + 1);
			visitnode[tree[s][i]] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	
	int N;
	cin >> N;
	for (int i = 0; i < (N - 1); i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	visitnode[1] = true;
	dfs(1, 0);
	cout << (cnt % 2 ? "Yes" : "No");
	return 0;
}