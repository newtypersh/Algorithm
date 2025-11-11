#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x, y, w, h, min = 10000;
	cin >> x >> y >> w >> h;
	if (x < min) {
		min = x;
	}
	if (y < min) {
		min = y;
	}
	if ((w - x) < min) {
		min = (w - x);
	}
	if ((h - y) < min) {
		min = (h - y);
	}
	cout << min;

	

    return 0;
}