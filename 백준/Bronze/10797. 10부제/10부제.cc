#include <iostream>

using namespace std;

int main() {
    
    int num, count=0;
    int car[5];
    cin >> num;
    num = num % 10;
    for (int i = 0; i < 5; i++) {
        cin >> car[i];
        if (car[i] == num) {
            count++;
        }
    }
    cout << count;

    return 0;
}

