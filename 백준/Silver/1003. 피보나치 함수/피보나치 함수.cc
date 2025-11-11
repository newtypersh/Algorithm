#include <iostream>
#include <cmath>
using namespace std;

int save[40] = { 0 };
int DP(int x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (save[x] != 0) return save[x];
	save[x] = DP(x - 1) + DP(x - 2);
	return save[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			cout << "1 0\n";
		}
		else {
			cout << DP(num - 1) << " " << DP(num) << "\n";
		}
	}
	
	return 0;
}