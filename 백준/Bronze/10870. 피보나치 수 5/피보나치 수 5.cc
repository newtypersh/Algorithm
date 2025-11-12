#include <iostream>
#include <cassert>
using namespace std;

int Fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main() {
	int n;
	cin >> n;
	cout << Fibonacci(n) << endl;
}
