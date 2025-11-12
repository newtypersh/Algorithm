#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string S;
	cin >> S;

	unordered_set<string> str;

	for (int i = 0; i < S.size(); i++) { // 시작 위치
		for (int j = i + 1; j <= S.size(); j++) { // 길이
			str.insert(S.substr(i, j - i)); // 시작 위치, 길이
		}
	}

	cout << str.size();

	return 0;
}