#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int n, num, sum=0, weight = 0, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);  // 각각의 로프 저장
        // 각각의 로프에 걸리는 중량을 구해야 한다.
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++) {
        sum += v[i];
        weight = sum / (i + 1);
        int temp = v[i] * (i + 1);
        if (temp > max)
            max = temp;
    }
    // ex) 15 10 => 15 20 
    // ex2) 15 14 13 12 11 => 15 28 39 48 55
    // 15 1 => 2
    // 1. (제일 무게가 낮은 밧줄 x 개수) || (하중 x 개수)
    // 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해야 함

    cout << max;

    return 0;
}
