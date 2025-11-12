#include <iostream>

using namespace std;

int N;
int minimum = 99999999;
int S[21][21];
bool selected[21];

void calculateSkill() {
	int skillA = 0, skillB = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (selected[i] && selected[j]) {
				skillA += S[i][j];
			}
			else if (!selected[i] && !selected[j]) {
				skillB += S[i][j];
			}
		}
	}
	int diff = abs(skillA - skillB);
	if (diff < minimum) {
		minimum = diff;
	}
}

void selectTeam(int count, int idx) {
	if (count == (N / 2)) {
		calculateSkill();
	}
	for (int i = idx; i <= N; i++) {
		
		selected[i] = true;
		selectTeam(count + 1, i + 1);
		selected[i] = false;
	}
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	selectTeam(0, 1);

	cout << minimum;

	return 0;
}
