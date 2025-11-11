#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool isDecimal(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i < n;i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	int num, input, count=0;
	cin >> num;
	for (int i = 0; i < num;i++) {
		cin >> input;
		arr.push_back(input);
	}

	for (auto v : arr) {
		if (isDecimal(v)) {
			count++;
		}
	}
	cout << count;
	

    return 0;
}