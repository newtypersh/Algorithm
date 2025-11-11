#include <iostream>

using namespace std;

int main() {
    
    int hour, min, sec, time, total=0;
    cin >> hour >> min >> sec >> time;
    total = (hour * 3600) + (min * 60) + sec + time;
    sec = total % 60;
    min = total / 60;
    hour = min / 60;
    min = min % 60;

    hour = hour % 24;

    cout << hour << " " << min << " " << sec;

    return 0;
}

