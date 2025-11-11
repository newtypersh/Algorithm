/*#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int countsix = 0;

	for (int i = 666; i <= 100000000; i++) {
		int num = i;
		while (num != 0) {
			if ((num % 10) == 6) {
				num /= 10;
				if ((num % 10) == 6) {
					num /= 10;
					if ((num % 10) == 6) {
						countsix++;
						break;
					}
				}
			}
			num /= 10;
		}
		if (countsix == n) {
			cout << i;
			break;
		}
	}

	return 0;
}
*/
/*
#include <iostream>
#include <string>

using namespace std;

int Findseries(int N)
{
	int i = 666;
	int series = 0;
	string target;
	while (1)
	{
		target = to_string(i);
		for (int j = 0; j < target.length() - 2; j++)
			if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')
			{
				series++;
				if (series == N)
					return i;
				break;
			}
		i++;
	}
}
int main() {
	int N;
	cin >> N;
	cout << Findseries(N);
}
*/
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, div5=0, div3=0;
	cin >> n;
	bool loopout = false;

	if ((n / 5) > 0) {
		for (int i = (n / 5); i >= 0; i--) {
			for (int j = 0; j <= (n / 3); j++) {
				if (((i * 5) + (j * 3)) == n) {
					div5 = i;
					div3 = j;
					cout << div5 + div3;
					loopout = true;
				}
				if (loopout) {
					break;
				}
			}
			if (loopout) {
				break;
			}
		}
		if(loopout == false){
			cout << -1;
		}
	}
	else if ((n / 5) == 0) {
		if ((n % 3) == 0) {
			div3 = n / 3;
			cout << div3;
		}
		else {
			cout << -1;
		}
	}

	return 0;
}