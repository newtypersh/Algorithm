#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);


    vector<int> a, b;
    int n, num, sum=0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    sort(a.rbegin(), a.rend());
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
    }

    for (int j = 0; j < a.size(); j++) {
        int min = b[0], index = 0;
        for (int i = 1; i < b.size(); i++) {
            if (min > b[i]) {
                min = b[i];
                index = i;
            }
        }
        sum += a[j] * min;
        b.erase(b.begin() + index);
    }
    
    cout << sum;

    return 0;
}
