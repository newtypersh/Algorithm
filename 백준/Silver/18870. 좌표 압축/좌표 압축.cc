#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v1, v2;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v1.push_back(num);
        v2.push_back(v1[i]);
    }

    // 오름차순 정렬
    sort(v2.begin(), v2.end());
    // unique 함수 사용 이후에 중복요소 제거 
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < n; i++) {
        // idx값은  v2의 시작부터 끝까지 탐색하면서 v1[i]이상의 숫자가 처음으로 나오는 위치의 인뎃스 번호를 반환한다.
        int idx = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        cout << idx << ' ';
    }

    return 0;
}
