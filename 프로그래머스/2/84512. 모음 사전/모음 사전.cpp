#include <string>
#include <vector>

using namespace std;

int ans = 1;
int answer = 0;

void dfs(string compare, int depth, string word) {
    if (compare == word) {
        ans = answer;
        return;
    }
    if (depth == 5) {
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            string prev = compare;
            string com = compare += 'A';
            if (depth != 5) {
                answer++;
                dfs(com, depth + 1, word);
            }
            compare = prev;
            

        }
        else if (i == 1) {
            string prev = compare;

            string com = compare += 'E';
            if (depth != 5) {
                ++answer;
                dfs(com, depth + 1, word);
            }
            compare = prev;

        }
        else if (i == 2) {
            string prev = compare;

            string com = compare += 'I';
            if (depth != 5) {
                ++answer;
                dfs(com, depth + 1, word);
            }
            compare = prev;

        }
        else if (i == 3) {
            string prev = compare;

            string com = compare += 'O';
            if (depth != 5) {
                ++answer;
                dfs(com, depth + 1, word);
            }
            compare = prev;

        }
        else {
            string prev = compare;

            string com = compare += 'U';
            if (depth != 5) {
                ++answer;
                dfs(com, depth + 1, word);
            }
            compare = prev;

        }
    }

}

int solution(string word) {
    
    string compair = "";
    dfs(compair, 0, word);
    answer = ans;
    return answer;
}
