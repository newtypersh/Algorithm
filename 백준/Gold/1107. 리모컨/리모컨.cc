#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

// 선택 가능한 모든 버튼
vector<int> numbers{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// DFS에서 선택한 원소의 번호
int sel[10]{ 0, };

// 입력
int N = 0, M = 0;

// 정답
int answer = INT_MAX;

void dfs(int s, int length)
{
    // length만큼 골랐다면?
    if (s == length)
    {
        int num = 0;

        // 앞에서부터 조립하여 숫자 생성 
        for (int i = 0; i < length; ++i)
            num += (pow(10, length - i - 1) * numbers[sel[i]]);

        // 최소값 갱신
        answer = min(answer, length + abs(N - num));
    }
    else
    {
        // 0부터 중복하여 선택
        for (int i = 0; i < numbers.size(); ++i)
        {
            sel[s] = i;
            dfs(s + 1, length);
        }
    }
}

int main() {
    int input;

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> input;
        numbers.erase(find(numbers.begin(), numbers.end(), input));
    }

    // 모든 버튼이 망가진경우?
    if (M == 10)
    {
        cout << abs(100 - N);
        return 0;
    }

    // 모든 버튼이 망가지지 않은경우?
    if (M == 0)
    {
        cout << min((int)to_string(N).size(), abs(100 - N));
        return 0;
    }

    int length = to_string(N).size();

    // 요구 자리 수 - 1
    if (length > 1)
        dfs(0, length - 1);

    // 요구 자리 수    
    dfs(0, length);

    // 요구 자리 수 + 1
    dfs(0, length + 1);

    cout << min(answer, abs(100 - N));

    return 0;
}