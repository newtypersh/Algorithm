#include <iostream>

using namespace std;

int main() {
    int L, P, total;
    int news[5];
    cin >> L >> P;
    total = L * P;
    for (int i = 0; i < 5; i++) {
        cin >> news[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << (news[i] - total) << " ";
    }


    return 0;
}

