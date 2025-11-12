#include <iostream>
#include <vector>
#include <queue>

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

using namespace std;

struct pipe
{
	int y;
	int x;
	int dir;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<vector<int>> house(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}

	vector<vector<int>> dp(N, vector<int>(N, 0));
	dp[0][1] = 1;
	queue<pipe> position; // (1,1) (1,2)로 시작
	position.push({ 0,1,HORIZONTAL });
	
	while (!position.empty()) {
		pipe cur = position.front();
		position.pop();

		if (cur.dir == HORIZONTAL) {
			if (cur.x + 1 < N && house[cur.y][cur.x + 1] != 1) {
				position.push({ cur.y,cur.x + 1,HORIZONTAL });
				dp[cur.y][cur.x + 1] += 1;
			}
			if (cur.x + 1 < N && cur.y + 1 < N && house[cur.y + 1][cur.x + 1] != 1 && house[cur.y + 1][cur.x] != 1 && house[cur.y][cur.x + 1] != 1) {
				position.push({ cur.y + 1,cur.x + 1,DIAGONAL });
				dp[cur.y + 1][cur.x + 1] += 1;
			}
		}
		else if (cur.dir == VERTICAL) {
			if (cur.y + 1 < N && house[cur.y + 1][cur.x] != 1) {
				position.push({ cur.y + 1,cur.x,VERTICAL });
				dp[cur.y + 1][cur.x] += 1;
			}
			if (cur.x + 1 < N && cur.y + 1 < N && house[cur.y + 1][cur.x + 1] != 1 && house[cur.y + 1][cur.x] != 1 && house[cur.y][cur.x + 1] != 1) {
				position.push({ cur.y + 1,cur.x + 1,DIAGONAL });
				dp[cur.y + 1][cur.x + 1] += 1;
			}
		}
		else {
			if (cur.x + 1 < N && house[cur.y][cur.x + 1] != 1) {
				position.push({ cur.y,cur.x + 1,HORIZONTAL });
				dp[cur.y][cur.x + 1] += 1;
			}
			if (cur.y + 1 < N && house[cur.y + 1][cur.x] != 1) {
				position.push({ cur.y + 1,cur.x,VERTICAL });
				dp[cur.y + 1][cur.x] += 1;
			}
			if (cur.x + 1 < N && cur.y + 1 < N && house[cur.y + 1][cur.x + 1] != 1 && house[cur.y + 1][cur.x] != 1 && house[cur.y][cur.x + 1] != 1) {
				position.push({ cur.y + 1,cur.x + 1,DIAGONAL });
				dp[cur.y + 1][cur.x + 1] += 1;
			}
		}
	}

	cout << dp[N - 1][N - 1];

	return 0;
}