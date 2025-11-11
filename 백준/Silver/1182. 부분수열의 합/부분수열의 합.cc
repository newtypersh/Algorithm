#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int cnt = 0;
vector<int> nums;
// N = 4, S = 5, { -3, -2, 5, 8 }
void DFS(int index, int sum) {
	sum += nums[index];
	if (sum == S) cnt++;
	for (int i = index + 1; i < N; i++) {
		DFS(i, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		DFS(i, 0);
	}
	cout << cnt;
}