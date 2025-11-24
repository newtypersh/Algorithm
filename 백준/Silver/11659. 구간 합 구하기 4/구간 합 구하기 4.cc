#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v(N + 1);
	vector<int> psum(N + 1);
	psum[0] = 0;
	
	for (int i = 1; i <= N; i++) { // 100,000
		cin >> v[i];
		psum[i] = psum[i - 1] + v[i];
	}

	int i, j;
	for (int n1 = 0; n1 < M; n1++) { // 100,000
		cin >> i >> j;
		cout << psum[j] - psum[i - 1] << '\n';
	}
	

	return 0;
}