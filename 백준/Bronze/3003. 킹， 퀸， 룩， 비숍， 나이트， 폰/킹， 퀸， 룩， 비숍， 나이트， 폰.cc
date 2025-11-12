#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
	int arr[] = { 1,1,2,2,2,8 };
	int num[6];
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 6; i++) {
		if (arr[i] > num[i]) {
			cout << (arr[i] - num[i]) << " ";
		}
		else if (arr[i] < num[i]) {
			cout << -(num[i] - arr[i]) << " ";
		}

		else {
			cout << 0 << " ";
		}
	}
}
