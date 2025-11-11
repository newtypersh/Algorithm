#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> v;
ll lo = 0, hi = 60000000000LL + 10, mid;
ll timeMin;

bool check(ll mid) {
    ll tempN = m; // 처음엔 모든 놀이기구에 아이들이 탑승
    for (ll i : v) {
        tempN += mid / i; // mid 시간 동안 각 놀이기구가 태울 수 있는 아이 수
    }
    return tempN >= n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    // 기본 케이스: 아이 수가 놀이기구 수보다 적거나 같은 경우
    if (n <= m) {
        cout << n;
        return 0;
    }

    // 이분 탐색으로 최소 시간 찾기
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            timeMin = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    // 마지막 아이가 타는 놀이기구 찾기
    ll findN = m;
    for (ll i : v) {
        findN += (timeMin - 1) / i; // timeMin-1 까지 탄 아이들 수
    }

    for (int i = 0; i < m; i++) {
        if (timeMin % v[i] == 0) { // timeMin에 탑승 가능한 놀이기구
            findN += 1;
            if (findN == n) {
                cout << i + 1;
                break;
            }
        }
    }

    return 0;
}
