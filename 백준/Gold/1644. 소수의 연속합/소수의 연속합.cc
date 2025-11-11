#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> prime;
int N, cnt = 0;
 
bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n) ; i++) {
		if ((n % i) == 0) return false;
	}
	return true;
}

void count() {
	int front = 0, back = 1, sum = prime[0];
	while (front != (prime.size() - 1)) {
		if (back == prime.size()) {
			sum -= prime[front];
			front++;
			if (sum == N) cnt++;
		}
		else {
			if (sum < N) {
				sum += prime[back];
				back++;
			}
			else if (sum > N) {
				sum -= prime[front];
				front++;
			}
			else {
				cnt++;
				sum += prime[back];
				back++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	if (N > 2) {
		for (int i = 2; i <= N; i++) {
			if (is_prime(i)) {
				prime.push_back(i);
			}
		}
		count();
	}
	else if (N == 2) {
		cnt++;
	}

	cout << cnt;
	return 0;
}