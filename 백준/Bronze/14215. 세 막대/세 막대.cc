#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	if (x >= (y + z)) {
		x = (y + z) - 1;
	}
	if (y >= (x + z)) {
		y = (x + z) - 1;
	}
	if (z >= (x + y)) {
		z = (x + y) - 1;
	}
	cout << (x + y + z);
	

	return 0;
}