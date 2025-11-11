#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, M;
	int arr1[101][101];
	int arr2[101][101];
	int total[101][101];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			total[i][j] = arr1[i][j] + arr2[i][j];
			cout << total[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
