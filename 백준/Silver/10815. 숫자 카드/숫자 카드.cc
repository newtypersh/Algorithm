#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int num;
	vector<int> v1;
	vector<int> v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(num);
	}
	sort(v1.begin(), v1.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		v2.push_back(num);
	}

	
	for (int i = 0; i < m; i++) {
		bool isSame = binary_search(v1.begin(), v1.end(), v2.at(i));
		if (isSame) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}
	return 0;
}