#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
int num[8];
int check[8];

void seq(int len) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			arr[len] = num[i];
			check[i] = true;
			seq(len + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num+N);

	seq(0);


	return 0;
}