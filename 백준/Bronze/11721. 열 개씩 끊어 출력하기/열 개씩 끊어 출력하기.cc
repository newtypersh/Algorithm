#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;
	int count = 0;

	for (int i = 0; i < str.size(); i++) {
		count++;
		cout << str[i];
		if (count % 10 == 0) {
			cout << endl;
		}
	}


	return 0;
}