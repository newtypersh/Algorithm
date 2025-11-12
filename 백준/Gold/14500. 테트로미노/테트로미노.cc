#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[500][500];
bool visited[500][500];
int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans = 0;

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = true;
        dfs(nx, ny, depth + 1, sum + arr[ny][nx]);
        visited[ny][nx] = false;
    }
}

void checkExtraShape(int x, int y) {
    // ㅗ
    if (x - 1 >= 0 && x + 1 < M && y - 1 >= 0)
        ans = max(ans, arr[y][x] + arr[y][x - 1] + arr[y][x + 1] + arr[y - 1][x]);
    // ㅜ
    if (x - 1 >= 0 && x + 1 < M && y + 1 < N)
        ans = max(ans, arr[y][x] + arr[y][x - 1] + arr[y][x + 1] + arr[y + 1][x]);
    // ㅓ
    if (y - 1 >= 0 && y + 1 < N && x - 1 >= 0)
        ans = max(ans, arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x - 1]);
    // ㅏ
    if (y - 1 >= 0 && y + 1 < N && x + 1 < M)
        ans = max(ans, arr[y][x] + arr[y - 1][x] + arr[y + 1][x] + arr[y][x + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(j, i, 1, arr[i][j]);
            visited[i][j] = false;
            checkExtraShape(j, i);
        }
    }

    cout << ans;
    return 0;
}
