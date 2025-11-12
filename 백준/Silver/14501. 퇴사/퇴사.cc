#include <iostream>
#define MAX 16
using namespace std;

int N;

int Ti[MAX] = {0,};
int Pi[MAX] = {0,};
int res[MAX] = {0,};

void DP() {
	int deadline;
	for (int i = N; i > 0; i--) {
		deadline = i + Ti[i];
		if (deadline > N + 1) {
			res[i] = res[i + 1];
		}
		else {
			res[i] = max(res[i + 1], res[deadline] + Pi[i]);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Ti[i] >> Pi[i];
	}
	DP();
	cout << res[1];
	return 0;
}