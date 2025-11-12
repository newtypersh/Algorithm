#include<iostream>
using namespace std;

int main() {
	int amount, number, total=0;
	cin >> amount;
	cin >> number;
	for (int i = 0; i < number; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		total = total + a * b;
	}
	if (amount == total) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}


}