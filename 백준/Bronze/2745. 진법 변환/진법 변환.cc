#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string N;
	int B;
	long long int print = 0;
	cin >> N >> B;

	for (int i = 0; i <N.length(); i++) {
		

		if (((N[i] - '0') < 10)&& ((int)N[i] >=0)) {
			print += (N[i] - '0') * pow(B, N.length() - (i + 1));
		}
		else if ((int)N[i] >= 65) {
			print += (N[i] - 55) * pow(B, N.length() - (i + 1));
		}
	}
	cout << print << "\n";
		
	return 0;
}