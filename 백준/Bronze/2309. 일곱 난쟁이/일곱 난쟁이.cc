#include <iostream>
#include <algorithm>
using namespace std;

bool is_print;
int arr[9];
int seven[7];

void dfs(int index, int depth, int sum) {
	if (depth == 7 ) {
		if (sum == 100 && !is_print) {
			for (int i = 0; i < 7; i++) {
				cout << seven[i] << '\n';
			}
			is_print = true;
		}
		return;
		
	}
	for (int i = index; i < 9; i++) {
		seven[depth] = arr[i];
		dfs(i + 1, depth + 1, sum + seven[depth]);
	}
}

int main() {
	
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	dfs(0, 0, 0);
	return 0;
}