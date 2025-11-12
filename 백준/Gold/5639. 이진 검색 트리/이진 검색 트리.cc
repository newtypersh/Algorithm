#include <iostream>
using namespace std;

int tree[10000];

void postOrder(int start, int end) {
	if (start >= end) return;
	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}
	int idx = start + 1;
	while (idx < end) {
		if (tree[idx] > tree[start]) {
			break;
		}
		idx++;
	}
	postOrder(start + 1, idx);
	postOrder(idx, end);
	cout << tree[start] << '\n';
}

int main() {
	int num;
	int idx = 0;
	while (cin >> num) {
		tree[idx++] = num;
	}
	postOrder(0, idx);
	return 0;
}