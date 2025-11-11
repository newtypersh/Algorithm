#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;

	int result = 0;
	string num = "";
	bool isMinus = false;


	for (int i = 0; i <= input.size(); i++) {
		if (i == input.size() || input[i] == '-' || input[i] == '+') {
			if (isMinus) {
				result -= stoi(num);
			}
			else {
				result += stoi(num);
			}
			num = "";

			if (input[i] == '-') {
				isMinus = true;
			}
		}
		else {
			num += input[i];
		}
	}


	cout << result;

	return 0;
}