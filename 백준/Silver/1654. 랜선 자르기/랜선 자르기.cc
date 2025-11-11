#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ParametricSearch(vector<int>& arr, int k, int n) {
	int low = 1;
	unsigned int high = arr[arr.size() - 1];
	unsigned int maxValue = 0;
	while (low <= high) {
		int total = 0;
		unsigned int mid = (low + high) / 2;
		for (int i = 0; i < k; i++) {
			total += arr[i] / mid;
		}
		if (total >= n) {
			low = mid + 1;
			maxValue = max(maxValue, mid);
		}
		else {
			high = mid - 1;
		}
	}
	cout << maxValue;
}

int main() {
	vector<int> length;
	int K, N, num;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> num;
		length.push_back(num);
	}
	sort(length.begin(), length.end());
	ParametricSearch(length, K, N);
	return 0;
}