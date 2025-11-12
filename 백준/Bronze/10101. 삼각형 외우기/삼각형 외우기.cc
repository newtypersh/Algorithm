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
	if ((x + y + z) == 180) {
		if ((x == y)&&(x == z)&&(y == z)) {
			cout << "Equilateral";
		}
		if (x == y) {
			if ((x != z) && (y != z)) {
				cout << "Isosceles";
			}
		}
		if (x == z) {
			if ((x != y) && (y != z)) {
				cout << "Isosceles";
			}
		}
		if (y == z) {
			if ((x != y) && (x != z)) {
				cout << "Isosceles";
			}
		}
		if ((x != y) && (x != z) && (y != z)) {
			cout << "Scalene";
		}
		
	}
	else {
		cout << "Error";
	}
	


	return 0;
}