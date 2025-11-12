#include <iostream>
#include <map>
using namespace std;

map<string, bool> ma;
int n, m;
string str;
int res = 0;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        ma.insert(pair<string, bool>(str, true));
    }
    for (int j = 0; j < m; j++) {
        cin >> str;
        if (ma[str] == true)
            res++;
    }
    cout << res;

    return 0;
}
