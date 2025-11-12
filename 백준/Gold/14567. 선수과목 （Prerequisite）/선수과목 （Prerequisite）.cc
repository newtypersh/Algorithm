#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{	
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1, 0);
	vector<int> semester(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		indegree[B]++;
	}


	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			semester[i] = 1;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			indegree[next]--;

			semester[next] = max(semester[next], semester[cur] + 1);

			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << semester[i] << ' ';
	}
	
	return 0;
}