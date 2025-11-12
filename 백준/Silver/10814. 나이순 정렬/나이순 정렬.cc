#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, string>> v;

    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }

    stable_sort(v.begin(), v.end(), compare);

    for (int k = 0; k < num ; k++) {
        cout << v[k].first << ' ' << v[k].second << '\n';
    }

    return 0;
}

