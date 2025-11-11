#include <iostream>

using namespace std;

int main() {
    int hour, min, plus, total=0;
    cin >> hour >> min;
    cin >> plus;
    total = (hour * 60) + min + plus;
    hour = total / 60;
    if (hour >= 24) {
        hour -= 24;
    }
    min = total % 60;
    cout << hour << " " << min;

}