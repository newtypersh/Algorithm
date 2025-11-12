#include <iostream>

using namespace std;

bool isSelf(int num) {
	for (int i = 1; i < num; i++) {
		int dn = i;
		int total = dn;
		while (dn > 0) {
			total = total + (dn % 10);
			dn /= 10;
		}
		if (total == num) {
			return false;
		}
	}
	return true;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		if (isSelf(i)) {
			cout << i << endl;
		}
	}
}