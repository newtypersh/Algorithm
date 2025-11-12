#include <iostream>
using namespace std;

int main(){
    int loop, a, b, cnt = 1;
    cin >> loop;
    while (loop>=cnt){
        cin >> a >> b;
        cout << "Case #" << cnt << ": "<< a+b << endl;
        cnt = cnt + 1;
    }
        
}