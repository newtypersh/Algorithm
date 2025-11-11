
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
int virus[101];
int ans=0;

void dfs(int x) {
	for (int i = 0;i< v[x].size(); i++) {
		int k = v[x][i];
		if (virus[k] == 0) {
			virus[k] = 1;
			ans++;
			dfs(k);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int a, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	virus[1] = 1;
	dfs(1);

	cout << ans;

	return 0;
}
