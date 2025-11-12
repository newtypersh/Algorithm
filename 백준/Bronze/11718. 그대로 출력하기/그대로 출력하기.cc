#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
	string str;
	int count = 0;
	while (true || (count<=100)) {
		getline(cin, str);
		assert(str.length() <= 100);
		if (str == "") {
			break;
		}
		cout << str << endl;
		count++;
	}
	return 0;
}