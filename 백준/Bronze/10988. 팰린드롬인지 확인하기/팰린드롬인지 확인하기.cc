#include <iostream>

using namespace std;

void reverse(string& str) {
	string temp(str);
	for (int i = 0; i < str.size(); i++) {
		str[i] = temp[str.size() - 1 - i];
	}
}

int main() {
	string str, compare;
	cin >> str;
	compare = str;
	reverse(str);
	if (compare == str) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}