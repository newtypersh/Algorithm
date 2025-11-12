#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, string, greater<>> m;
	string name, cmd;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> cmd;
		m[name] = cmd;
	}

	map<string, string>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == "enter") {
			cout << it->first << '\n';
		}
	}

	return 0;
}