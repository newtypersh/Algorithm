#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int str=0;
	int x, cnt = 0, num = 0;
	cin >> x;
	if (x == 1) {
		cout << 1;
		return 0;
	}

	while ((x / 2) > 1) {
		if (x % 2 == 1) {
			str |= (1 << cnt);
			num++;
		}
		cnt++;
		x /= 2;
	}
	
	if (x == 3) {
		str |= (1 << (cnt + 1));
		str |= (1 << (cnt));
		num += 2;
	}
	else if (x == 2) {
		str |= (1 << cnt + 1);
		num++;
	}

	cout << num;

	return 0;
}