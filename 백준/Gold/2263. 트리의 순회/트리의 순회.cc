#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int in[MAX];
int post[MAX];
int in_temp[MAX];

void sol(int in_s, int in_f, int post_s, int post_f) {
	if (in_s > in_f || post_s > post_f) {
		return;
	}

	int root = post[post_f];
	int rootIndex = in_temp[root];
	int leftSize = rootIndex - in_s;
	int rightSize = in_f - rootIndex;
	int in_Rpos = in_temp[root];

	cout << root << ' ';
	sol(in_s, rootIndex - 1, post_s, post_s + leftSize - 1);
	sol(rootIndex + 1, in_f, post_s + leftSize, post_f - 1);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		in[i] = num;
		in_temp[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		post[i] = num;
	}
	sol(0, n - 1, 0, n - 1);
	return 0;
}
