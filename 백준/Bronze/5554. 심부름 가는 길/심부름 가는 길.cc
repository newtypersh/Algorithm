#include <iostream>

using namespace std;

int main() {
    int time[4], total = 0;
    for (int i = 0; i < 4; i++) {
        cin >> time[i];
        total += time[i];
    }

    cout << total / 60 << "\n";
    cout << total % 60;

    return 0;
}

