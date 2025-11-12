#include <iostream>
#include <string>

using namespace std;

bool isps(string str) {
	int total = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			total++;
		}
		else if (str[i] == ')') {
			total--;
		}
		if (total < 0) {
			return false;
			break;
		}
	}
	if (total == 0) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (isps(str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}

// ())(()