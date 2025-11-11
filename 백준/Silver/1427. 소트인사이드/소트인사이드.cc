#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(char a, char b) {
    return a > b;
}

int main() {
    
    string str;
    cin >> str;
    
    sort(str.begin(), str.end(), comp);
   
    cout << str;
}

