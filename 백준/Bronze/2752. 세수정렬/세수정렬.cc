#include <iostream>

using namespace std;

void numsort(int num[]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (num[j] > num[j + 1]) {
                int tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int num[3] = { 0 };

    for (int i = 0; i < 3; i++) {
        cin >> num[i];
    }

    numsort(num);

    for (int i = 0; i < 3; i++) {
        cout << num[i] << " ";
    }

    return 0;
}

