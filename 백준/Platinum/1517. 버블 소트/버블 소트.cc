#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v;
vector<int> tmp;
long long result = 0;

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;
    int cnt = 0;
    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++];
            result += (long long)cnt;
        }
        else {
            tmp[k++] = v[j++];
            cnt++;
        }
    }

    if (i > mid) {
        int s = j;
        while (s <= end) {
            tmp[k++] = v[s++];
            cnt++;
        }
    }
    else {
        int s = i;
        while (s <= mid) {
            tmp[k++] = v[s++];
            result += (long long)cnt;
        }
    }

    for (int t = start; t <= end; t++) {
        v[t] = tmp[t];
    }
}

void mergesort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(start, mid);
        mergesort(mid + 1, end);
        merge(start, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    v.resize(n, 0);
    tmp.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergesort(0, n - 1);
    cout << result;
    return 0;
}
