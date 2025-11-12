#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[3];
    for (int i = 0; i < 3; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (num[j] > num[j + 1]) {
                int tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }

    cout << num[1];

    return 0;
}

