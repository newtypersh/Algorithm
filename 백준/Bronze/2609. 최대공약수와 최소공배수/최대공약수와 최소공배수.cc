#include <iostream>

using namespace std;


int main() {
    
    unsigned int num1, num2;
    
    bool out1 = false;
    bool ou2 = false;
    
    cin >> num1 >> num2;

    for (int i = 1; i <= num1; i++) {
        for (int j = 1; j <= num2; j++) {
            if ((num1%i == 0)&&(num2%j == 0)) {
                if ((num1 / i) == (num2 / j)) {
                    cout << num1 / i << endl;
                    ou2 = true;
                    break;
                }
            }
        }
        if (ou2) {
            break;
        }
        
    }
    
    for (int i = 1; i <= 100000;i++) {
        for (int j = 1; j <= 100000; j++) {
            if ((num1 * i) == (num2 * j)) {
                cout <<  num1 * i;
                out1 = true;
                break;
            }
            if ((num1 * i) < (num2 * j)) {
                break;
            }
        }
        if (out1) {
            break;
        }
    }
    
    return 0;
}

