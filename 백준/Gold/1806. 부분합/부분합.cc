#include <iostream>
#include <vector>
using namespace std;

int n, s;
int min_length = 100001;

void TwoPointer(vector<int> v, int s) {
	int front = 0, back = 1, sum = v[0];
	while (front != (v.size() - 1)) {
		if (back == v.size()) {
			if (sum >= s) {
				if (min_length > (back - front)) {
					min_length = (back - front);
				}
			}
			sum -= v[front];
			front++;
		}
		else {
			if (sum >= s && back > front) {
				if (min_length > (back - front)) {
					min_length = (back - front);
				}
				sum -= v[front];
				front++;
			}
			else {
				sum += v[back];
				back++;
			}
		}
	}
	if (v[front] >= s) {
		min_length = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	TwoPointer(v, s);
	if (min_length == 100001) {
		cout << 0;
	}
	else {
		cout << min_length;
	}
	return 0;
}