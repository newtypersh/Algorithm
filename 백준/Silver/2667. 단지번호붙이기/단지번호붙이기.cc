#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 26

using namespace std;
int graph[MAX][MAX];
bool visited[MAX][MAX];

int N;
int cnt = 1;
int x_dir[4] = { -1, 1, 0, 0 };
int y_dir[4] = { 0, 0, -1, 1 };

vector<int> cntVec;
queue<pair<int, int>> q;

void bfs(int start_x, int start_y) {
    visited[start_x][start_y] = true;
    q.push(make_pair(start_x, start_y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < N) && !visited[x_new][y_new] && graph[x_new][y_new] == 1) {
                visited[x_new][y_new] = true;
                q.push(make_pair(x_new, y_new));
                cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    int res = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            graph[i][j] = str[j] - '0';
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                cnt = 1;
                bfs(i, j);
                cntVec.push_back(cnt);
                res++;
            }
        }
    }

    sort(cntVec.begin(), cntVec.end());
    cout << res << '\n';
    for (int i = 0; i < cntVec.size(); i++) {
        cout << cntVec[i] << '\n';
    }

    return 0;
}
