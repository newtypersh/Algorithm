#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> inDegree;
vector<int> buildTime;
vector<int> elapsedTime;

int N;

void topologicalSort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			elapsedTime[i] = buildTime[i];
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int next : graph[curr]) {
			elapsedTime[next] = max(elapsedTime[next], elapsedTime[curr] + buildTime[next]);
			if (--inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	
	cin >> N;
	graph.resize(N + 1);
	inDegree.assign(N + 1, 0);
	buildTime.assign(N + 1, 0);
	elapsedTime.assign(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		buildTime[i] = num;
		cin >> num;
		while (num != -1) {
			graph[num].push_back(i);
			inDegree[i]++;
			cin >> num;
		}
	}
	topologicalSort();
	for (int i = 1; i <= N; i++) {
		cout << elapsedTime[i] << ' ';
	}
	
}