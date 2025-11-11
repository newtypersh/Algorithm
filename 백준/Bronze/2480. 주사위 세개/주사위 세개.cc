#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3, money=0, max=0;
    cin >> num1 >> num2 >> num3;
    if ((num1==num2)&&(num1==num3)&&(num2==num3)) {
        money = 10000 + (num1 * 1000);
    }
    else if ((num1==num2)&&(num1!=num3)){
        money = 1000 + (num1 * 100);
    }
    else if ((num1==num3)&&(num1!=num2)) {
        money = 1000 + (num1 * 100);
    }
    else if ((num2==num3)&&(num1!=num2)) {
        money = 1000 + (num2 * 100);
    }
    else {
        max = num1;
        if (num2 > max) {
            max = num2;
        }
        if (num3 > max) {
            max = num3;
        }
        money = max * 100;
    }
    cout << money;

}