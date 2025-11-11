#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char str[15];
vector<char> arr;

bool check_vc() {
	int consonant = 0, vowel = 0;

	for (int i = 0; i < arr.size(); i++) {
		char c = arr[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			vowel++;
		}
		else {
			consonant++;
		}
	}

	if (vowel >= 1 && consonant >= 2) {
		return true;
	}
	else {
		return false;
	}
}


void dfs(int index, int depth) {
	if (depth == L) {
		for (int i = 0; i < L; i++) {
			cout << arr[i];
		}
		cout << '\n';
		return;
	}

	for (int i = index; i < C; i++) {
		arr.push_back(str[i]);
		if (depth < (L - 1) || check_vc()) {
			dfs(i + 1, depth + 1);
		}
		arr.pop_back();
	}

}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> str[i];
	}
	sort(str, str + C);
	dfs(0, 0);
	return 0;
}