#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int e, s, m;
	int num = 1;
	cin >> e >> s >> m;
	
	while (true) {
		if (((num % 15) == 0) && e == 15) {
			if (num % 28 == s) {
				if (num % 19 == m) {
					break;
				}
				else if ((num % 19 == 0) && (m == 19)) {
					break;
				}
			}
			else if ((num % 28 == 0) && (s == 28)) {
				if (num % 19 == m) {
					break;
				}
				else if ((num % 19 == 0) && (m == 19)) {
					break;
				}
			}
		}
		else if ((num % 15) == e) {
			if (num % 28 == s) {
				if (num % 19 == m) {
					break;
				}
				else if ((num%19 == 0) && (m == 19)) {
					break;
				}
			}
			else if ((num%28 == 0) && (s == 28)) {
				if (num % 19 == m) {
					break;
				}
				else if ((num % 19 == 0) && (m == 19)) {
					break;
				}
			}
		}
		num++;
	}
	cout << num;

	return 0;
}
