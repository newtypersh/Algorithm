#include <iostream>
#include <cassert>
using namespace std;

void reverse(int arr[],int i, int j) {
	int tmp[101];
	int count = 0;
	for (int k = i; k <= j; k++) {
		tmp[k] = arr[k];
	}
	for (int h = i; h <= j; h++) {
		arr[h] = tmp[j - count];
		count++;
	}
}

int main() {
	int N, M, arr[101];
	int i, j;
	cin >> N >> M;

	for (int k = 1; k <= N; k++) {
 		arr[k] = k;
	}

	for (int k = 1; k <= M; k++) {
		cin >> i >> j;
		if (i != j) {
			reverse(arr, i, j);
		}
	}

	for (int k = 1; k <= N; k++) {
		cout << arr[k] << " ";
	}
	return 0;
}