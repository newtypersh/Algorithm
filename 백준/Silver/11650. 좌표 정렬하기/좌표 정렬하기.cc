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

    //vector<vector<int>> v;
    //vector<int> v2(2,0);

    //int num1=0, num2=0;
    //for (int i = 0; i < n; i++) {
    //    cin >> num1 >>num2;
    //    v2.push_back(num1);
    //    v2.push_back(num2);
    //    v.push_back(v2);
    //}

    //for (auto a : v) {
    //    cout << a[0] << " " << a[1] << "\n";
    //}

    vector<pair<int, int>> v;

    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> num1 >> num2;
        v.push_back(make_pair(num1, num2));
    }

    sort(v.begin(), v.end());
    

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}

