#include <string>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> max_user;

    // 최대 수용인원 초기화
    for (int i = 0; i < 24; i++)
        max_user.push_back(m - 1);

    for (int i = 0; i < players.size(); i++) {
        if (players[i] > max_user[i]) {
            int needs = players[i] - max_user[i];
            // 증설 서버 수 계산
            int add_cnt = needs / m;
            if (needs % m > 0) add_cnt++;

            // 증설 카운트 증가
            answer += add_cnt;

            // 추후 수용 인원 업데이트
            for (int j = i; j < i + k; j++) {
                if (j >= players.size()) break; // 최대 배열 초과 → 종료
                max_user[j] += add_cnt * m;
            }
        }
    }
    return answer;
}
