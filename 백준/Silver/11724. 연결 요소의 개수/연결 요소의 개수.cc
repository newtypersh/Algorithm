#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int N, M;
int connected_count = 0;

void dfs(int start) {
	stack<int> s;
	s.push(start);

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!visited[next]) {
				visited[next] = true;
				s.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	graph.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			connected_count++;
		}
	}

	cout << connected_count;

	return 0;
}