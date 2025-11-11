#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> region;


void ParametricSearch() {
	int low = 0;
	int high = region[region.size() - 1];
	int result = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			
			sum += min(region[i], mid);
			
		}
		if (sum <= M) {
			result = max(mid, result);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
}

int main() {
	int request, sum = 0, max = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> request;
		region.push_back(request);
		sum += request;
		if (max < request) {
			max = request;
		}
	}
	cin >> M;
	if (sum <= M) {
		cout << max;
	}
	else {
		sort(region.begin(), region.end());
		ParametricSearch();
	}
	
	return 0;
}