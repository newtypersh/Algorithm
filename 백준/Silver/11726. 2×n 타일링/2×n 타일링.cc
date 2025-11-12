#include <iostream>

using namespace std;

long long arr[1001] = { 0 };

long long fibo(int x) {
	if (arr[x] != 0) {
		return arr[x];
	}

	arr[x] = (fibo(x - 1) + fibo(x - 2))%10007;

	return arr[x];
}
  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long num;
	cin >> num;

	arr[1] = 1;
	arr[2] = 2;

	
	cout << fibo(num);
	

	return 0;
}