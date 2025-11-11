#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num, new_num,count = 0;
	cin >> num;
	new_num = num;
	do {
		new_num = ((new_num % 10) * 10) + ((new_num / 10) + (new_num % 10)) % 10;
		count++;
	} while (new_num != num);
	
	cout << count;

	return 0;
}