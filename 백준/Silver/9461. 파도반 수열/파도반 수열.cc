#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	long long length[101];
	length[1] = 1;
	length[2] = 1;
	length[3] = 1;

	for (int i = 4; i <= 100; i++) {
		length[i] = length[i - 2] + length[i - 3];
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << length[N] << '\n';
	}
	

	return 0;
}