#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> tree;

void BinarySearch(long long m) {
	long long low = 0; // 4
	long long high = tree[tree.size() - 1]; // 46
	long long solution = 0;
	while (low <= high) {
		long long cut = (low + high) / 2; // 25
		long long sum = 0;
		for (int i = 0; i < tree.size(); i++) {
			if ((tree[i] - cut) > 0) {
				sum += tree[i] - cut;
			}
		}
		if (sum >= m) {
			solution = cut;
			low = cut + 1;
		}
		else {
			high = cut - 1;
		}
	}
	
	cout << solution;
	

}

int main() {
	long long n, m, h;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> h;
		tree.push_back(h);
	}

	sort(tree.begin(), tree.end());
	BinarySearch(m);

	return 0;
}