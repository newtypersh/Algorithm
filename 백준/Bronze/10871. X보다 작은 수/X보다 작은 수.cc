#include <iostream>

using namespace std;

int main() {
	unsigned int N, X;
	cin >> N >> X;
	int num[10001];
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++) {
		if (num[i] < X) {
			cout << num[i] << " ";
		}
	}
}