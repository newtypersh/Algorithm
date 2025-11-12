#include <iostream>
#include <vector>
#include <list>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	while (true) {
		int num, total = 0;
		
		cin >> num;
		if (num == -1) {
			break;
		}
		for (int i = 1; i < num; i++) {
			if (num % i == 0) {
				arr.push_back(i);
			}
		}
		for (auto k = arr.begin(); k != arr.end(); k++) {
			total += *k;
		}
		if (total == num) {
			cout << num << " = ";
			for (auto k = arr.begin(); k != arr.end(); k++) {
				if (k != arr.end()-1) {
					cout << *k << " + ";
				}
				else {
					cout << *k;
				}
			}
		}
		else {
			cout << num << " is NOT perfect.";
		}
		cout << endl;

		arr.clear();
	}
	

    return 0;
}