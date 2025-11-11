#include <iostream>

using namespace std;

int main() {
    int hour, min, total = 0;
    cin >> hour >> min;
    total = (hour * 60) + min;
    total -= 45;
    hour = total / 60;
    if (total < 0) {
        hour = 23;
    }
    
    if (total < 0) {
        min += 15;
        min %= 60;
    }
    else {
        min = total % 60;
    }
    cout << hour << " " << min;

}