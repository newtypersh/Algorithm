#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x[4], y[4];
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}

	if (x[0] == x[1]) {
		x[3] = x[2];
	}
	if (x[1] == x[2]) {
		x[3] = x[0];
	}
	if (x[0] == x[2]) {
		x[3] = x[1];
	}

	if (y[0] == y[1]) {
		y[3] = y[2];
	}
	if (y[1] == y[2]) {
		y[3] = y[0];
	}
	if (y[2] == y[0]) {
		y[3] = y[1];
	}

	cout << x[3] << " " << y[3] << endl;

    return 0;
}