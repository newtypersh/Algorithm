#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	int num;
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		bool isFound = binary_search(v.begin(), v.end(), num);
		if (isFound)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}