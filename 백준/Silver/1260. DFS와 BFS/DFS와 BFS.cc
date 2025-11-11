#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
bool visited[1001];
vector<int> graph[1001];


void dfs(int start) {
    visited[start] = true;
    cout << start << ' ';
    for (int i = 0; i < graph[start].size(); i++) {
        int y = graph[start][i];
        if (!visited[y])
            dfs(y);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n1, n2;
    int v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for (int i = 0; i < 1001; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << '\n';
    for (int i = 0; i < 1001; i++) {
        visited[i] = false;
    }
    bfs(v);
    return 0;
}
