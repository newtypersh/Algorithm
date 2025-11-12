#include <iostream>

using namespace std;

int main() {
    
    int L, A, B, C, D, math=0, korean=0,max=0;
    cin >> L >> A >> B >> C >> D;

    if ((A % C) == 0) {
        korean += A / C;
    }
    else if ((A % C) != 0) {
        korean = (A / C) + 1;
    }

    if ((B % D) == 0) {
        math += B / D;
    }
    else if ((B % D) != 0) {
        math += B / D + 1;
    }

    if (korean >= math) {
        max = L - korean;
    }
    else if (math >= korean) {
        max = L - math;
    }

    cout << max;

    return 0;
}

