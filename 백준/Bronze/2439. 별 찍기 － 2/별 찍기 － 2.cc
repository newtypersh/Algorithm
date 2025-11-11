#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        for (int j = num; j >= 1; j--) {
            if (i >= j) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}