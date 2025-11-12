#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int max = 0;

	string str[5];

	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		if (max < str[i].length()) {
			max = str[i].length();
		}
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].length() <= i) {
				continue;
			}
			else {
				cout << str[j].at(i);
			}
		}
	}

	return 0;
}