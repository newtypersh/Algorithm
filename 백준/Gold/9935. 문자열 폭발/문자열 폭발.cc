#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, bomb, result;
	cin >> str >> bomb;

	for (int i = 0; i < str.length(); i++) {
		result += str[i];

		if (result.size() >= bomb.size()) {
			if (result.substr(result.size() - bomb.size(), bomb.size()) == bomb) {
				result.erase(result.end() - bomb.size(), result.end());
			}
		}
	}

	cout << (result.empty() ? "FRULA" : result);
}