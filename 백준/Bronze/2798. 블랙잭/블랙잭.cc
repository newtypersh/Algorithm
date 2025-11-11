#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, num, goal, sum = 0;
    int min = 9999999;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if (M - sum < min && M - sum >= 0) {
                    min = M - sum;
                    goal = sum;
                }
            }
        }
    }
        
            
    cout << goal;
}