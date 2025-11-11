#include <iostream>
#include <string>
using namespace std;

int dp[101][101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str1, str2, str3;

    cin >> str1 >> str2 >> str3;

    int len1 = str1.size();
    int len2 = str2.size();
    int len3 = str3.size();

    str1 = " " + str1;
    str2 = " " + str2;
    str3 = " " + str3;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            for (int k = 1; k <= len3; k++) {
                if ((str1[i] == str2[j]) && (str1[i] == str3[k]) && (str2[j] == str3[k])) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }

    cout << dp[len1][len2][len3];
    
    return 0;
}