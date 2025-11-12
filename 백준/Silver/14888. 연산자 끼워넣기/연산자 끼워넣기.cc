#include <iostream>
#include <vector>
using namespace std;

int N, minNum = 1000000001, maxNum = -1000000001;
int op[4];
int A[11];

void backtrack(int num, int depth) {
    if (depth == N-1) {
        if (num > maxNum) {
            maxNum = num;
        }
        if (num <  minNum) {
            minNum = num;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            switch(i) {
            case 0:
                op[0]--;
                backtrack(num + A[depth+1], depth + 1);
                op[0]++;
                break;
            case 1:
                op[1]--;
                backtrack(num - A[depth + 1], depth + 1);
                op[1]++;
                break;
            case 2:
                op[2]--;
                backtrack(num * A[depth + 1], depth + 1);
                op[2]++;
                break;
            case 3:
                op[3]--;
                backtrack(num / A[depth + 1], depth + 1);
                op[3]++;
                break;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    backtrack(A[0], 0);
    cout << maxNum << '\n' << minNum;
}