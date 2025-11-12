#include <iostream>

using namespace std;


int main() {
    
    int num, total = 0;
    
    for (int i = 0; i < 5; i++) {
        cin >> num;
        if (num < 40) {
            num = 40;
        }
        total += num;
    }

    cout << total / 5;
    
    return 0;
}

