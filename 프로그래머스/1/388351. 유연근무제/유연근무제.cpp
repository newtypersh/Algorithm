#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int n = schedules.size();
    int answer = n;
    for(int i=0;i<n;i++){
        bool remove = false;
        
        schedules[i] += 10;
        if((schedules[i] % 100) > 59){
            schedules[i] += 40;
        }
        
        for(int j=0; j<7;j++){
            int currentday = (startday + j);
            if(currentday > 7){
                currentday = (currentday % 7);
            }
            if(currentday >= 6 && currentday <= 7){
                continue;
            }
            if(timelogs[i][j] > schedules[i]){
                remove = true;
                break;
            }
        }
        if(remove){
            answer--;
        }
    }
    
    return answer;
}