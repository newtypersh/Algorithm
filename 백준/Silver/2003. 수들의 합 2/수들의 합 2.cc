#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N+1, 0);
    int current_sum = 0;
    int count = 0;
    int left = 1;
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int right = 1; right <= N; right++) {
        current_sum += A[right];
        while (current_sum > M and left <= right) {
            current_sum -= A[left];
            left += 1;
        }

        if (current_sum == M) {
            count++;
        }
    }

    cout << count;
    
    
    return 0;
}