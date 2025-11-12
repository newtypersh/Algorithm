#include <iostream>

using namespace std;

int main() {
    int num;
    int arr[101];
    int v;

    cin >> num;

    for (int i = 1; i <= num; i++) {
        cin >> arr[i];
    }
    cin >> v;
    
    int res = 0;
    for (int i = 1; i <= num; i++) {
        if (arr[i] == v) {
            res++;
        }
    }
    cout << res;
}