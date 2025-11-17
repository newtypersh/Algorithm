#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	int N, digit;
	string str;
	long long count = 1;
	queue<string> q;
	

	cin >> N;
	str = to_string(N);
	q.push(str);
	
	
	while (!q.empty()) {
		string tmp = q.front();
		q.pop();
		
		if (tmp.size() == 1) continue;

		string temp1 = tmp.substr(0, tmp.size() - 1);
		string temp2 = tmp.substr(1, tmp.size());

		

		if (temp1 != temp2) {
			q.push(temp1);
			q.push(temp2);
			count++;

		}
		else {
			q.push(temp1);
		}
		
	}

	cout << count;

	return 0;
}