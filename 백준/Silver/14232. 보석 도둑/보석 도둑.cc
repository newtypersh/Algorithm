#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> factors;
long long k;
int cnt = 0;

void PrimeFactorizaion() {
    while (k % 2 == 0) {
        k /= 2;
        cnt++;
        factors.push_back(2);
    }
    
    for (int i = 3; i <= sqrt(k); i++) {
        while (k % i == 0) {
            k /= i;
            cnt++;
            factors.push_back(i);
        }
    }
    
    if (k > 1) {
        cnt++;
        factors.push_back(k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> k;
    PrimeFactorizaion();
    cout << cnt << '\n';
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i] << ' ';
    }
    return 0;
}