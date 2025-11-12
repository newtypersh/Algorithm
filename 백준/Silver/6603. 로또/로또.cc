#include <iostream>
#include <vector>
using namespace std;

int k;

void select(vector<int> v) {
	int arr[6];
	for (int i = 0; i < k - 5; i++) {
		arr[0] = v[i];
		for (int j = i + 1; j < k - 4; j++) {
			arr[1] = v[j];
			for (int l = j + 1; l < k - 3; l++) {
				arr[2] = v[l];
				for (int m = l + 1; m < k - 2; m++) {
					arr[3] = v[m];
					for (int n = m + 1; n < k - 1; n++) {
						arr[4] = v[n];
						for (int o = n + 1; o < k; o++) {
							arr[5] = v[o];
							for (int p = 0; p < 6; p++) {
								cout << arr[p] << ' ';
							}
							cout << '\n';
						}
					}
				}
			}
		}
	}
	cout << '\n';
}

int main() {
	while (true) {
		cin >> k;
		if (k == 0) break;
		vector<int> s;
		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;
			s.push_back(num);
		}
		select(s);
	}
	
	return 0;
}