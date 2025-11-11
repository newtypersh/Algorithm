#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> map;
	vector<string> v;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		string str;
		cin >> str;
		map[str]++;
		if (map[str] > 1)
			v.push_back(str);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto o : v) {
		cout << o << '\n';
	}

	return 0;
}