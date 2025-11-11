#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

void sort(int arr[], int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int num;
	cin >> num;
	int arr[1001];
	assert(num >= 1 && num <= 1000);
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr, num);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}