#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    int current_sum = 0;
    int left = 0;
    int max_value = -1000000;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int right = 0; right < N; right++) {
        current_sum += v[right];
        if ((right - left) == (K - 1)) {
            max_value = max(current_sum, max_value);
            current_sum -= v[left];
            left++;
        }
    }

    cout << max_value;
    
    return 0;
}