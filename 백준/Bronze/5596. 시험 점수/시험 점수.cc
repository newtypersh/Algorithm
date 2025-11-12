#include <iostream>

using namespace std;

int main() {
    
    int minkook[4], min_total=0;
    int manse[4], man_total=0;
    for (int i = 0; i < 4; i++) {
        cin >> minkook[i];
        min_total += minkook[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> manse[i];
        man_total += manse[i];
    }

    if (man_total > min_total) {
        cout << man_total;
    }
    else {
        cout << min_total;
    }

    return 0;
}

