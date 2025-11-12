#include <iostream>

using namespace std;

int main() {
	int N, total = 0;
	cin >> N;
	
	char N2;

	
	for (int i = 1; i <= N; i++) {
		cin >> N2;
		total += (N2 - '0');
	}
	
	cout << total;
	
}