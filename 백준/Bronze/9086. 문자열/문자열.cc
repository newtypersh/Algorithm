#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int num;
	cin >> num;
	string str;
	int last = 0;
	for (int i = 0; i < num; i++) {
		cin >> str;
		last = str.length();
		cout << str[0] << str[last-1] << endl;
	}
}