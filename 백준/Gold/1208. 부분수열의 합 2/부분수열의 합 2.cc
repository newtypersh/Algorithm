/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;

void dfs(int start, int end, vector<ll>& part, ll sum) {
	if (start > end) {
		part.push_back(sum);
		return;
	}
	else {
		dfs(start + 1, end, part, sum);
		dfs(start + 1, end, part, sum + v[start]);
	}
}

int main() {
	int n, c;
	cin >> n >> c;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll> part1;
	vector<ll> part2;
	dfs(0, (n / 2) - 1, part1, 0);
	dfs((n / 2), n - 1, part2, 0);
	sort(part2.begin(), part2.end());
	int cnt = 0;
	for (int i = 0; i < part1.size(); i++) {
		ll x = c - part1[i]; // x는 더 담을 수 있는 무게
		cnt += upper_bound(part2.begin(), part2.end(), x) - part2.begin();
		// part2 에서 x를 초과하는 위치의 인덱스
	}
	cout << cnt;
	return 0;
}
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> v;

void dfs(int start, int end, vector<int>& part, int sum) {
	if (start > end) {
		part.push_back(sum);
		return;
	}
	else {
		dfs(start + 1, end, part, sum + v[start]);
		dfs(start + 1, end, part, sum);
	}
}

int main() {
	int n, s;
	cin >> n >> s;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> part1;
	vector<int> part2;
	dfs(0, (n / 2) - 1, part1, 0);
	dfs((n / 2), n - 1, part2, 0);
	sort(part2.begin(), part2.end());
	long long cnt = 0;
	for (int i = 0; i < part1.size(); i++) {
		int x = s - part1[i];
		cnt += upper_bound(part2.begin(), part2.end(), x) - lower_bound(part2.begin(), part2.end(), x);
	}
	cnt += s == 0 ? -1 : 0;
	cout << cnt;
	return 0;
}