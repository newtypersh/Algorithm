#include <iostream>
#include <cmath>
using namespace std;

int N, r, c, ans = 0;

void divide_and_conquer(int size, int x, int y) {
	if (c == x && r == y) {
		cout << ans;
		return;
	}
	else if (c < x + size && r < y + size && c >= x && r >= y) {
		divide_and_conquer(size / 2, x, y);
		divide_and_conquer(size / 2, x + (size / 2), y);
		divide_and_conquer(size / 2, x, y + (size / 2));
		divide_and_conquer(size / 2, x + (size / 2), y + (size / 2));
	}
	else {
		ans += size * size;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> r >> c;
	divide_and_conquer(pow(2, N), 0, 0);
	return 0;
}