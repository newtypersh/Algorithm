#include <iostream>

using namespace std;


int main() {
    
    int num;
    cin >> num;
    for (int i = num; i >= 1; i--) {
        for (int j = num; j >= 1; j--) {
            if (i >= j) {
                cout << "*";
            }
        }
        cout << endl;
    }
    
    return 0;
}

