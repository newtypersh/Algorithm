#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> num1 >> num2;
        v.push_back(make_pair(num1, num2));
    }
    

    for (int i = 0; i < n; i++) {
        int count = 1;
        //cout << v[i].first << " " << v[i].second << "\n";
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if ((v[i].first < v[j].first) && (v[i].second < v[j].second)) {
                    count++;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}

