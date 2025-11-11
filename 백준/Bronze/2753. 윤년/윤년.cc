#include <iostream>
using namespace std;
int main(){
    int yy = 0;
    cin >> yy;
    if (yy%4 == 0){
        if(yy%100 != 0){
            cout << "1";
        }
        else if(yy%400 == 0){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    else{
        cout << "0";
    }
}