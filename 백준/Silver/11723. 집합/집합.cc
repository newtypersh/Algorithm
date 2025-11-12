#include <iostream>

using namespace std;

int n = 20;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int m, x;
	cin >> m;

	int s = 0;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			x--;
			s |= (1 << x);
		}
		else if (str == "remove") {
			cin >> x;
			x--;
			s &= ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;
			x--;
			int check = (s & (1 << x));
			cout << (check ? 1 : 0) << '\n';
		}
		else if (str == "toggle") {
			cin >> x;
			x--;
			s ^= (1 << x);
		}
		else if (str == "all") {
			s = (1 << n) - 1;
		}
		else if (str == "empty") {
			s = 0;
		}
		else {
			i--;
		}
	}
	return 0;
}