#include <iostream>

using namespace std;

int main() {
	int Case = 1;
	int L, P, V;
	cin >> L >> P >> V;
	while (L != 0 || P != 0 || V != 0) {
		int div = V / P;
		int rest = (V % P) > L ? L : (V % P);
		int sum = rest + (div * L);
		
		cout << "Case " << Case << ": " << sum << '\n';
		cin >> L >> P >> V;
		Case++;
	}
	return 0;
}