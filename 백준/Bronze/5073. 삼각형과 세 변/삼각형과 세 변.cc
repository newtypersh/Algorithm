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
	do {
		if ((z >= (x + y)) || y >= (x + z) || x >= (y + z)) {
			cout << "Invalid" << endl;
		}
		else {
			if ((x == y) && (x == z) && (y == z)) {
				cout << "Equilateral" << endl;
			}
			if (x == y) {
				if ((x != z) && (y != z)) {
					cout << "Isosceles" << endl;
				}
			}
			if (y == z) {
				if ((x != z) && (x != y)) {
					cout << "Isosceles" << endl;
				}
			}
			if (x == z) {
				if ((x != y) && (y != z)) {
					cout << "Isosceles" << endl;
				}
			}
			if ((x != y) && (x != z) && (y != z)) {
				cout << "Scalene" << endl;
			}
		}

		
		cin >> x >> y >> z;
	} while ((x != 0) && (y != 0) && (z != 0));
	
	

	return 0;
}