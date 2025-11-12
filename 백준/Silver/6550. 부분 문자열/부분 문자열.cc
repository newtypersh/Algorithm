#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 태스트 케이스 수?
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s, t;
	while (cin >> s >> t) {
		int n = s.size();
		int m = t.size();

		vector<vector<int>> v(n + 1, vector<int>(m + 1));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i - 1] == t[j - 1]) {
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				else {
					v[i][j] = max(v[i - 1][j], v[i][j - 1]);
				}
			}
		}

		if (v[n][m] == n) cout << "Yes\n";
		else cout << "No\n";
	}
		

	return 0;
}