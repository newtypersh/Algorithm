#include <iostream>
#include <cassert>
using namespace std;

bool isPalindrome(int num) { // 12321
	int compare = 0;
	int origin = num;
	while (num != 0) {
		compare *= 10; //0 10 120 1230
		compare += num % 10; // 1 12 123 123
		num /= 10; // 1232 123 12
	}
	if (origin == compare) {
		return true;
	}
	return false;
}

int main() {
	int num;
	cin >> num;
	assert(num >= 0 && num <= 99999);
	while (num != 0) {
		if (isPalindrome(num)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		cin >> num;
		assert(num >= 0 && num <= 99999);
	}
	return 0;
}