#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void backtrack(int number, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = number; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            backtrack(i + 1, depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    backtrack(1, 0);
    return 0;
}