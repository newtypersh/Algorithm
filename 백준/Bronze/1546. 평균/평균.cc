#include <iostream>
#include <cassert>
using namespace std;

void sort(double subject[], int N) {
	for (int i = 1; i <= N-1; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (subject[j] > subject[j + 1]) {
				int tmp = subject[j];
				subject[j] = subject[j + 1];
				subject[j + 1] = tmp;
			}
		}
	}
}

void setting(double subject[], double a, int b) {
	for (int i = 1; i <= b; i++) {
		subject[i] = (subject[i] / a * 100);
	}
}

int main() {
	int N;
	double avg = 0, total = 0;
	double subject[1001] = { 0 };
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> subject[i];
	}

	sort(subject, N);

	setting(subject, subject[N], N);

	for (int i = 1; i <= N; i++) {
		total += subject[i];
	}

	avg = total / N;

	cout << avg << endl;

	return 0;
}