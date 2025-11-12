#include <iostream>

using namespace std;


int main() {
    
    int menu1, menu2, menu3, min_menu = 2000,min_drink=2000, cola, cider;
    cin >> menu1 >> menu2 >> menu3 >> cola >> cider;
    
    if (menu2 >= menu3) {
        if (min_menu > menu3) {
            min_menu = menu3;
        }
    }
    else if (menu3 > menu2) {
        if (min_menu > menu2) {
            min_menu = menu2;
        }
    }

    if (min_menu > menu1) {
        min_menu = menu1;
    }

    if (cola >= cider) {
        if (min_drink > cider) {
            min_drink = cider;
        }
    }
    else if (cider > cola) {
        if (min_drink > cola) {
            min_drink = cola;
        }
    }


    cout << min_menu + min_drink - 50;
    return 0;
}

