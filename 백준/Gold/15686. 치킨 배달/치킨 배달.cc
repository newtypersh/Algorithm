/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, M;
int arr[51][51];
bool visited[51][51];
vector<pair<int, int>> chicken_list;
queue<pair<int, int>> q;
int minimum_value = INF;


int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void input();
void find_minimum_value();
void dfs(int cnt);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    input();
    cout << minimum_value;
    return 0;
}

void input() {
    cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> arr[r][c];         
            if (arr[r][c] == 2) {
                chicken_list.push_back({ r,c });
            }
        }
    }
}
void find_minimum_value() {
    int temp_minimum_value = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (arr[r][c] == 1) {
                q.push({ r,c }); // 집을 push
            }
        }
    }

    queue<pair<int, int>> temp_q;

    
    while (!q.empty()) {
        temp_q.push(q.front());
        q.pop();
        int count = 0;
        int dist[51][51] = { 0 };
        bool isBreak = false;
        while (!temp_q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            

            for (int i = 0; i < 4; i++) {
                int new_r = r + dr[i];
                int new_c = c + dc[i];

                if (new_r < 1 || new_c < 1 || new_r > N || new_c > N) continue;
                if (visited[new_r][new_c] == true) {

                }
                

            }
        }
        temp_minimum_value += count;
    }
    
}
void dfs(int cnt) {
    if (cnt == M) {
        find_minimum_value();
    }
    for (int i = 1; i <= chicken_list.size(); i++) {
        int r = chicken_list[i].first;
        int c = chicken_list[i].second;
        if (!visited[r][c]) {
            visited[r][c] = true;
            dfs(cnt + 1);
            visited[r][c] = false;
        }
    }
}
*/

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
#define MAX 50
using namespace std;


int N, M, Chicken_Num, Answer;
int MAP[MAX][MAX];
bool Select[13];
vector<pair<int, int>> House, Chicken, V;

int Min(int A, int B) {
    if (A < B) return A;
    return B;
}

void Input() {
    Answer = 99999999;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1) House.push_back(make_pair(i, j));
            if (MAP[i][j] == 2) Chicken.push_back(make_pair(i, j));
        }
    }
    Chicken_Num = Chicken.size();
}

int Calculate_Distance() {
    int Sum = 0;
    // 모든 house를 탐색
    for (int i = 0; i < House.size(); i++) {
        int x = House[i].first;
        int y = House[i].second;
        int d = 99999999;
        // 모든 치킨집을 탐색
        for (int j = 0; j < V.size(); j++) {
            int xx = V[j].first;
            int yy = V[j].second;
            // 특정 house와 모든 치킨집들간의 최단 거리를 탐색
            int Dist = abs(xx - x) + abs(yy - y);
            d = Min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}

void Select_Chicken(int Idx, int Cnt) {
    if (Cnt == M) {
        Answer = Min(Answer, Calculate_Distance());
        return;
    }

    // idx를 입력으로 받으면 visited가 필요가 없음
    for (int i = Idx; i < Chicken_Num; i++) {
        if (Select[i] == true) continue;
        Select[i] = true;
        V.push_back(Chicken[i]);
        Select_Chicken(i, Cnt + 1);
        Select[i] = false;
        V.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Select_Chicken(0, 0);
    cout << Answer << endl;

    return 0;
}