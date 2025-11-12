#include <iostream>

using namespace std;

int main() {
	int count;
	int min = 1000000;
	int max = -1000000;

	cin >> count;
	int array;

	for (int i = 0; i < count; i++) {
		cin >> array;
		if (max < array) {
			max = array;
		}
		if (min > array) {
			min = array;
		}
	}
	cout << min << ' ' << max;
}