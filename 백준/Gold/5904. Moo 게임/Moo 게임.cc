/*
#include <iostream>

using namespace std;

char s1[3] = { 'm','o','o' };

void moo(int n, int k, int len) {
	int new_len = len * 2 + k + 3;
	if (n <= 3) {
		cout << s1[n - 1];
		return;
	}
	if (new_len < n) {
		moo(n, k + 1, new_len);
	}
	else {
		if (n > len && n <= len + k + 3) {
			if (n - len != 1) {
				cout << "o\n";
			}
			else {
				cout << "m\n";
			}
			return;
		}
		else {
			moo(n - (len + k + 3), 1, 3);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	moo(N, 1, 3);
	
	return 0;
}
*/

#include <iostream>

using namespace std;

char str[3] = { 'm', 'o', 'o' };

void moo(int n, int k, int len) {
	int new_len = (len * 2) + (k + 3);
	if (n <= 3) {
		cout << str[n - 1];
		return;
	}
	if (new_len < n) {
		moo(n, k + 1, new_len);
	}
	else {
		if (n > len && n <= len + k + 3) {
			if (n == len + 1) {
				cout << "m";
			}
			else {
				cout << "o";
			}
			return;
		}
		else {
			moo(n - (len + k + 3), 1, 3);
		}
	}
}

int main() {
	int n;
	cin >> n;
	moo(n, 1, 3);
	return 0;
}