#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	int count = 0;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[i + 1]) {
			count++;
		}
	}

	if (!count) {
		cout << count;
	}
	else {
		cout << count/2;
	}
	

	return 0;
}