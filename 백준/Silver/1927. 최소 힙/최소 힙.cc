#include <iostream>
#include <queue>                                                                              
#include <vector>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> result;
    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, cmp> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) {
            q.push(x);
        }
        else {
            if (q.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
    
    
    return 0;
}
