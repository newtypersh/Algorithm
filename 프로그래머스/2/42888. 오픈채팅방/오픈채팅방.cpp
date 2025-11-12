#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for (int i = 0; i < record.size(); i++) {
        string key, value, act;
        int phase = 1;
        for (int j = 0; j < record[i].size(); j++) {
            

            if (phase == 2 && record[i][j] != ' ') {
                key += record[i][j];
            }
            else if(phase == 3) {
                value += record[i][j];
            }

            if (record[i][j] == ' ') {
                phase++;
            }
        }
        if (record[i][0] != 'L') {
            m[key] = value;
        }
    }

    for (int i = 0; i < record.size(); i++) {
        string str, key;
        int phase = 1;
        for (int j = 0; j < record[i].size(); j++) {
            
            if (phase == 2 && record[i][j] != ' ') {
                key += record[i][j];
            }
            else if(phase == 3){
                break;
            }

            if (record[i][j] == ' ') {
                phase++;
            }
        }

        if (record[i][0] == 'E') {
            str = m[key] + "님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if (record[i][0] == 'L') {
            str = m[key] + "님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    return answer;
}