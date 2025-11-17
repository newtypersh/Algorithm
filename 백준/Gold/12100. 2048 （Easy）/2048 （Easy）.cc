#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N; // 크기
int map[21][21] = {0,}; // input
int ans = 0; // 정답
vector<vector<int>> dir; // 패턴을 담아두는 벡터

// 패턴 경우의 수를 계산하는 백트래킹
void getPossibleCase(int x, vector<int> v){
    // 벡터에 담긴 방향의 개수가 5개라면
    if(v.size() >= 5) {
        // 완성된 패턴 v를 dir에 담음
        dir.push_back(v);
        return;
    }
    // 상하좌우로 움직이는 모든 경우의 수를 계산
    for(int i = 0; i < 4; i++){
        v.push_back(i); // 해당 방향으로 움직이는 경우
        getPossibleCase(i,v); // 그 방향으로 움직이고, 그 다음 움직임
        v.pop_back(); // 다른 움직임 계산을 위해 담아뒀던 방향 i를 제거
    }
}


// 5번 움직이는 함수
void simulation(vector<int> move){
    int cmap[21][21]; // 입력으로 주어진 맵을 복사한 맵
    int tmp[21][21]; // 한번 이동한 후, 맵의 상태를 임시로 저장할 공간
    copy(&map[0][0],&map[0][0]+21*21,&cmap[0][0]);
    queue<int> q[N+1]; // N개의 큐 생성

    // move 담겨있는 순서대로 실행
    for(int k = 0; k < move.size(); k++){
        fill(&tmp[0][0],&tmp[20][21],0); // tmp 배열 초기화
        switch(move[k])
        {
            //위
            case 0:
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++) {
                    if(cmap[j][i] == 0) continue;
                    q[i].push(cmap[j][i]);
                }
            break;

            // 아래
            case 1:
            for(int i = 1; i <= N; i++)
                for(int j = N; j >= 1; j--) {
                    if(cmap[j][i] == 0) continue;
                    q[i].push(cmap[j][i]);
                }
            break;

            // 좌
            case 2:
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++) {
                    if(cmap[i][j] == 0) continue;
                    q[i].push(cmap[i][j]);
                }
            break;

            // 우
            case 3:
            for(int i = 1; i <= N; i++)
                for(int j = N; j >= 1; j--) {
                    if(cmap[i][j] == 0) continue;
                    q[i].push(cmap[i][j]);
                }
            break;
        }

        // 첫번째 큐부터 검사
        for(int j = 1; j <= N; j++){
            int idx = 1; // 맵에 인덱스 위해 필요한 offset
            while(!q[j].empty()){
                // 맨 위에 하나를 뽑음
                int get = q[j].front();
                q[j].pop();
                
                // 하나를 뽑았을 때 더 이상 없을수도 있음
                // get과 큐의 맨 위가 같을 때
                if(!q[j].empty() && get == q[j].front()){
                    // 합침
                    get += q[j].front();
                    // 맨위에 꺼 뽑음
                    q[j].pop();
                }
                ans = max(ans,get); // 제일 큰 값을 정답으로 함

                // 방향에 따라 넣는 맵의 위치를 다르게 해야함
                switch(move[k]){
                    // 위
                    case 0: tmp[idx][j] = get;
                    break;
                    // 아래
                    case 1: tmp[N-idx+1][j] = get;
                    break;
                    // 좌
                    case 2: tmp[j][idx] = get;
                    break;
                    // 우
                    case 3: tmp[j][N-idx+1] = get;
                    break;
                }
                idx++; // 하나 쌓았으니 인덱스+1
            }
        }
        copy(&tmp[0][0],&tmp[0][0]+21*21,&cmap[0][0]); // 결과를 cmap에 옮김
    }
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) cin >> map[i][j];
        
    vector<int> tmp;
    getPossibleCase(0,tmp);

    for(int i = 0; i < dir.size(); i++){
        simulation(dir[i]);
    }
    cout << ans;
    return 0;
}