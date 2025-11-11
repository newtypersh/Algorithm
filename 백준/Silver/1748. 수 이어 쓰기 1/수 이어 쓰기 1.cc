#include <iostream>
#include <cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long int answer = 0;
	cin >> n; // e.g. 120
	int digit = 1;

	// 자리수 구하기
	for (; digit <= 10; digit++) {
		if (!(n / (int)pow(10, digit - 1))) {
			--digit;
			break;
		}
	}
	// digit = 3


	for (int i = 1; i < digit; ++i) {
		answer += (pow(10, i) - pow(10, i - 1)) * i;
	}
	// answer += 10
	// answer += (100 - 10) * 2 = 180

	answer += (n - (int)pow(10, digit - 1) + 1) * digit;
	// answer += (120 - (100) + 1) * 3 = 57
	
	cout << answer; // answer = 252
	return 0;
}