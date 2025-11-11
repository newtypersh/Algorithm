#include <iostream>
#include <string>
using namespace std;



int main() {
	int cnt = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c') {
			if ((str[i + 1]) == '='){
				cnt++;
				i++;
			}
			else if (str[i + 1] == '-') {
				cnt++;
				i++;
			}
			else {
				cnt++;
			}
		}

		else if (str[i] == 'd') {
			if ((str[i + 1] == 'z') && (str[i + 2] == '=')) {
				cnt++;
				i += 2;
			}
			else if (str[i + 1] == '-') {
				cnt++;
				i++;
			}
			else {
				cnt++;
			}
		}

		else if ((str[i] == 'l') || (str[i] == 'n')) {
			if (str[i + 1] == 'j') {
				cnt++;
				i++;
			}
			else {
				cnt++;
			}
		}

		else if ((str[i] == 's') || (str[i] == 'z')) {
			if (str[i + 1] == '=') {
				cnt++;
				i++;
			}
			else {
				cnt++;
			}
		}

		else {
			cnt++;
		}

	}
	cout << cnt;
}
