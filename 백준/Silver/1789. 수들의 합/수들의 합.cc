#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long s;
	int n = 0, num = 0;
	cin >> s;

	while (s > 0) {
		n++;
		s -= n;
	}
	if (s < 0) {
		n--;
	}
	cout << n;

	return 0;
}