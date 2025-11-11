#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[1001];

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int sum = 0;
    pair<int, int> res;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        sum += num;
        arr[num]++;
        if (res.first < arr[num]) {
            res.first = arr[num];
            res.second = num;
        }

    }
    cout << sum / 10 << '\n' << res.second;

    return 0;
}
