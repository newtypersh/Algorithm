#include <iostream>
#include <string>

using namespace std;

int main() {
	int loop, cent;
	int quarter = 25, dime = 10, nickel = 5, peny = 1;
	cin >> loop;
	for (int i = 0; i < loop; i++) {
		cin >> cent;
		cout << cent / quarter << " ";
		cent = cent % quarter;
		cout << cent / dime << " ";
		cent = cent % dime;
		cout << cent / nickel << " ";
		cent = cent % nickel;
		cout << cent / peny << endl;
	}
}