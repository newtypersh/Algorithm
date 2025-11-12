#include <iostream>

using namespace std;

int main() {
    
    int per, want, money, need;
    cin >> per >> want >> money;

    need = (per * want) - money;

    if (need < 0) {
        need = 0;
    }

    cout << need;

    return 0;
}

