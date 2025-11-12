#include <iostream>

using namespace std;

int main() {
	int N, M;
	int a[101];

	for (int i = 1; i <= 100; i++) {
		a[i] = i;
	}

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		int temp = a[num1];
		a[num1] = a[num2];
		a[num2] = temp;
	}

	for (int i = 1; i <= N; i++) {
		cout << a[i] << " ";
	}
}