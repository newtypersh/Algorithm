#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int C, N;
    cin >> C >> N;

    const int INF = 1000000000;
    vector<int> dp(C + 101, INF);
    vector<int> cost(N);
    vector<int> people(N);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        cin >> cost[i] >> people[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = people[i]; j < C + 101; j++) {
            if (dp[j - people[i]] != INF) {
                dp[j] = min(dp[j], dp[j - people[i]] + cost[i]);
            }
        }
    }


    int ans = INF;
    for (int i = C; i < C + 101; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans;
    
    return 0;
}