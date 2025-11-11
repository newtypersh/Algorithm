#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	cin >> num;
	for (int i = num; i >= 1; i--) {
		cout << i << "\n";
	}
	return 0;
}

