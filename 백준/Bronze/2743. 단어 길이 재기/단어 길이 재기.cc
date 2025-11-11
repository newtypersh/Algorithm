#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		count += 1;
	}
	cout << count;
}