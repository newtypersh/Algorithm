#include<iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> sorted;
int n, num, sol = -1, cnt = 0;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int l;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            sorted[k++] = v[i++];
        }
        else {
            sorted[k++] = v[j++];
        }
    }

    if (i > mid) {
        for (l = j; l <= right; l++) {
            sorted[k++] = v[l];
        }
    }
    else {
        for (l = i; l <= mid; l++) {
            sorted[k++] = v[l];
        }
    }

    for (l = left; l <= right; l++) {
        v[l] = sorted[l];
        cnt++;
        if (cnt == num) {
            sol = v[l];
            return;
        }
    }
}

void merge_sort(int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> num;
    v.resize(n, 0);
    sorted.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    merge_sort(0, n - 1);
    cout << sol;
    return 0;
}
