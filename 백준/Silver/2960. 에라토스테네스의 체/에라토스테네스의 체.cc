#include <iostream>
using namespace std;

bool num[1001] = { false, };

int main() {
	int N, K;
	int cnt = 0, ans = -1;
	num[0] = num[1] = true;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		if (num[i]) continue;
		else {
			for (int j = 1; j * i <= N; j++) {
				if (!num[i * j]) {
					num[i * j] = true;
					cnt++;
					if (cnt == K) {
						ans = i * j;
					}
				}
			}
		}
	}
	
	
	cout << ans;
	return 0;
}