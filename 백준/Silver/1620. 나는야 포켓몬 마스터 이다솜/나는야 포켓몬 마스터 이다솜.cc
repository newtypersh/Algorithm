#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    map<string, int> map;
    vector<string> name;
    int n, m;
    string temp;
    cin >> n >> m;
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        name.push_back(temp);
        map.insert(make_pair(temp, i));
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (temp[0] >= 65 && temp[0] <= 90) {
            result.push_back(to_string(map[temp]));
        }
        else {
            result.push_back(name[stoi(temp) - 1]);
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    
    return 0;
}
