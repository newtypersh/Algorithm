#include <iostream>

using namespace std;

int main() {
	int arr[31];

	for (int i = 1; i <= 30; i++) {
		arr[i] = i;
	}

	for (int i = 1; i <= 28; i++) {
		int num;
		cin >> num;
		for (int i = 1; i <= 30; i++) {
			if (num == arr[i]) {
				arr[i] = 0;
			}
		}
	}

	for (int i = 1; i <= 30; i++) {
		if (arr[i] != 0) {
			cout << i << " ";
		}
	}
}