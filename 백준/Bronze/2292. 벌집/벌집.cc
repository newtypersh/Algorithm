#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	//1=0, 2~7=1, 8~19=3, 20~37=4, 38~58=5
	//1, 6, 12, 18, 24
	int i = 0;
	for (int sum = 2; sum <= num; i++) {
		sum += 6 * i;
	}
	if (num == 1) i = 1;
	cout << i;
	return 0;
}