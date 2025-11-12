#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++) {
		int num = 97 + i;
		int out = -1;
		for (int j = 0; j < str.size(); j++) {
			if ((int)str[j] == num) {
				out = j;
				break;
			}
		}
		cout << out << " ";
	}
}