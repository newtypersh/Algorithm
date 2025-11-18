#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void calc(int from, int via, int to, int num) {
	if (num == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}

	calc(from, to, via, num - 1);
	cout << from << ' ' << to << '\n';
	calc(via, from, to, num - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	long long answer = pow(2, N) - 1;
	cout << answer << '\n';

	calc(1, 2, 3, N);

	return 0;
}