#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num;
	int pow = 1;
	do {
		cin >> num;
	} while (num < 1 && num>15);
	
	for (int i = 1; i <= num; i++) {
		pow *= 2;
	}
	cout << (1 + pow) * (1 + pow) << "\n";
	
}