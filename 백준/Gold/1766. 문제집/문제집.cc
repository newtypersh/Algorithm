#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> inDegree;
vector<int> sequence;

int N, M;

void topologicalSort() {
	priority_queue<int, vector<int>, greater<int>> q;
	
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.top();
		q.pop();
		sequence.push_back(curr);
		
		for (int next : graph[curr]) {
			if (--inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	
	cin >> N >> M;

	graph.resize(N + 1);
	inDegree.assign(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		inDegree[B]++;
	}
	topologicalSort();
	for (int i = 0; i < N; i++) {
		cout << sequence[i] << ' ';
	}
}