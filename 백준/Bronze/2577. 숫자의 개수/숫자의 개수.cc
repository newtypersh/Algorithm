#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	int total = 0;
	cin >> A >> B >> C;
	total = A * B * C;
	int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
	while (total != 0) {
		switch (total % 10) {
		case 0:
			count0++;
			break;
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		case 3:
			count3++;
			break;
		case 4:
			count4++;
			break;
		case 5:
			count5++;
			break;
		case 6:
			count6++;
			break;
		case 7:
			count7++;
			break;
		case 8:
			count8++;
			break;
		case 9:
			count9++;
			break;
		}
		total /= 10;
	}
	cout << count0 << "\n" << count1 << "\n" << count2 << "\n" << count3 << "\n" << count4 << "\n" << count5 << "\n" << count6 << "\n" << count7 << "\n" << count8 << "\n" << count9 << "\n";

	return 0;
}