#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int arr[1000000];
//
//void sort(int *arr, unsigned int n) {
//	
//	for (int i = 0; i < n - 1; i++) {
//		bool outofloop = true;
//		for (int j = 0; j < n - 1; j++) {
//			
//			if (*(arr+j) > *(arr + j + 1)) {
//				int tmp = *(arr+j);
//				*(arr+j) = *(arr+j + 1);
//				*(arr+j + 1) = tmp;
//				outofloop = false;
//			}
//
//		}
//		if (outofloop == false) {
//			break;
//		}
//	}
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> N;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int number;
		cin >> number;
		N.push_back(number);
	}

	sort(N.begin(), N.end());

	for (int i = 0; i < num; i++) {
		cout << N.at(i) << "\n";
	}

	

	return 0;
}