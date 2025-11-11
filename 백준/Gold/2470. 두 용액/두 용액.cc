#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> liquid;

void TwoPointer() {
	int var1 = 0, var2 = 0;
	int low = 0;
	int high = liquid.size() - 1;
	int min = 2000000001;
	while (low != high) {
		int sum = liquid[low] + liquid[high];
		if (abs(sum) < min) {
			var1 = low;
			var2 = high;
			min = abs(sum);
		}

		if (sum < 0) {
			low++;
		}
		else {
			high--;
		}

	}
	cout << liquid[var1] << ' ' << liquid[var2];
}

int main() {
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		liquid.push_back(num);
	}
	sort(liquid.begin(), liquid.end());
	TwoPointer();
	return 0;
}