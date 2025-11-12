#include <iostream>

using namespace std;

int main() {
	unsigned int N, M;
	cin >> N >> M;
	int num[101] = { 0, };
	int first, end, number;
	for (int i = 1; i <= M; i++) {
		cin >> first >> end >> number;
		for (int j = first; j <= end; j++) {
				num[j] = number;
		}

	}
	for (int i = 1; i <= N; i++) {
			cout << num[i] << " ";
	}
	
}