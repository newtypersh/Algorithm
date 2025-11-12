#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num, count1 = 0, count2 =0;
	cin >> num;

	if (num != 1) {
		while (num != 0) {
			int i = 0;
			for (i = 2; i < num; i++) {
				if (num % i == 0) {
					cout << i << endl;
					num /= i;
					count1++;
					break;
				}
			}
			count2++;
			if (count2 > count1) {
				break;
			}
		}
		cout << num;
	}

	

    return 0;
}