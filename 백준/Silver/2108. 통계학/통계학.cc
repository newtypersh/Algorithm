#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int num[500001];
int arithmetic_mean() {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += num[i];
    }
    return round(ans / n);
}// 산술평균
int medain() {
    return num[(n - 1) / 2];
} //중앙값
int mode() {
    int cnt = 0;
    int ans = 0;
    int temp = num[0];
    int result = num[0];
    bool second = false;
    for (int i = 0; i < n; i++) {
        if (temp == num[i]) {
            cnt++;
        }
        else {
            if (ans < cnt) {
                ans = cnt;
                result = num[i - 1];
                second = false;
            }
            else if (ans == cnt && !second) {
                result = num[i - 1];
                second = true;
            }
            cnt = 1;
            temp = num[i];
        }
    }
    if (ans < cnt) {
        result = num[n - 1];
    }
    else if (ans == cnt && !second) {
        result = num[n - 1];
    }
    return result;
}//최빈값
int mode2() {
    int result;
    int count = 0;
    int cnt2[8001] = { 0 };
    for (int i = 0; i < n; i++) {
        cnt2[num[i] + 4000]++;
    }
    int max_mode = *max_element(cnt2, cnt2 + 8001);
    for (int i = 0; i < 8001; i++) {
        if (cnt2[i] == max_mode) {
            count++;
            result = i - 4000;
        }
        if (count == 2) {
            break;
        }
    }
    return result;
} 
int range() {
    return num[n - 1] - num[0];
}//범위
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    cout << arithmetic_mean() << '\n';
    cout << medain() << '\n';
    cout << mode2() << '\n';
    cout << range() << '\n';
    return 0;
}
