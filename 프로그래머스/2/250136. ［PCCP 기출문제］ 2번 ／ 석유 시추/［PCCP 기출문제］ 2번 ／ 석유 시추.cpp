#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    vector<int> column_oil(m, 0);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && land[i][j] == 1) {
                int oil_count = 0;
                unordered_set<int> columns;
                queue<pair<int, int>> q;
                
                q.push({i, j});
                visited[i][j] = true;
                
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    oil_count++;
                    columns.insert(y);
                    
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && land[nx][ny] == 1) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                
                for(int col : columns){
                   column_oil[col] += oil_count;
                }
            }
            
            
        }
    }
    
    return *max_element(column_oil.begin(), column_oil.end());
}