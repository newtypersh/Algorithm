#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	long long count = 0;
	for (int i = 0; i < N - 2; i++) {
		int j = i + 1;
		int k = N - 1;
		while (j < k) {
			int sum = v[i] + v[j] + v[k];
			if (sum < 0) j++;
			else if (sum > 0) k--;
			else {
				if (v[j] == v[k]) {
					int cnt = k - j + 1;
					count += (cnt * (cnt - 1)) / 2;
					break;
				}

				int cnt_j = 1, cnt_k = 1;

				while (j + 1 < k && v[j] == v[j + 1]) {
					cnt_j++;
					j++;
				}

				while (k - 1 > j && v[k] == v[k - 1]) {
					cnt_k++;
					k--;
				}

				count += (cnt_j * cnt_k);
				j++;
				k--;
			}
		}
	}
	cout << count;

	return 0;
}