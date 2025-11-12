#include <iostream>
#include <cassert>
using namespace std;

void sort(int arr[]) {
	int tmp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main() {
	int num[10], count = 1, re = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num[i];
		num[i] = (num[i] % 42);
	}

	sort(num);

	
	for (int j = 0; j < 9; j++) {
		if (num[j] != num[j + 1]) {
			count++;
				
		}	
	}
		
	

	cout << count;

	return 0;
}