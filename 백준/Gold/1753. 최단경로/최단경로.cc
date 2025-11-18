#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
	// {비용, 목적지}를 저장하는 우선순위 큐
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;
		int now = pq.top().second;
		pq.pop(); 

		if (dist[now] < d) continue;
		
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;    // 목적지
			int cost = d + graph[now][i].first; // 목적지로 가는 가중치

			if (cost < dist[next]) {
				dist[next] = cost;
				pq.push({ cost, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V, E, K;
	int u, v, w;

	cin >> V >> E >> K;
	graph.resize(V + 1);
	dist.resize(V + 1, INF);
	
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		
		graph[u].push_back({ w, v }); // 비용(w), 목적지(v) 순으로 저장
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}