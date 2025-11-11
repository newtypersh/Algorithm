#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num[9];
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	int maxValue = -1;
	int maxValueIndex;
	for (int i = 0; i < 9; i++) {
		if (num[i] > maxValue) {
			maxValue = num[i];
			maxValueIndex = i;
		}
	}

	cout << maxValue << "\n";

	cout << maxValueIndex + 1;
	return 0;
}