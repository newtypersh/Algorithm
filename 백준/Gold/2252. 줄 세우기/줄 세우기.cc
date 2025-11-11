#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologySort(int n, vector<vector<int>>& adj, vector<int>& in_degree) {
    vector<int> result(n + 1);
    queue<int> in_zero;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            in_zero.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = in_zero.front();
        in_zero.pop();
        result[i] = x;
        for (int y : adj[x]) {
            if (--in_degree[y] == 0) in_zero.push(y);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> in_degree(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        in_degree[B]++;
    }
    topologySort(N, adj, in_degree);

    return 0;
}
