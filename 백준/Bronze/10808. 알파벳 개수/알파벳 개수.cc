#include <iostream>

using namespace std;


int main() {
    int count[26] = {0};

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        int input = str[i] - 97;
        count[input]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << count[i] << " ";
    }

    return 0;
}

