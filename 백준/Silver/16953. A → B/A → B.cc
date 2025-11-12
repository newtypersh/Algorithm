#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int A, B;
	int count = 0;
	cin >> A >> B;

	while (A < B) {
		if ((B % 2) == 0) {
			B /= 2;
			count += 1;
		}
		else if((B % 10) == 1){
			B /= 10;
			count += 1;
		}
		else {
			break;
		}
	}

	if (A == B) {
		cout << count + 1;
	}
	else {
		cout << -1;
	}

	return 0;
}