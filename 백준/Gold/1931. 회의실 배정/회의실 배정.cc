#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<pair<int, int>> schedule;
    vector<pair<int, int>> v;
    int start, end;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        schedule.push_back(make_pair(end, start));
    }

    sort(schedule.begin(), schedule.end());

    int time = schedule[0].first;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (time <= schedule[i].second) {
            count++;
            time = schedule[i].first;
        }
    }
    cout << count;
    return 0;
}
