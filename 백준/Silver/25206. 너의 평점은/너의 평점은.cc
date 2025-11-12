#include <iostream>
#include <string>
#include <vector>
using namespace std;




int main() {
	string subject[20];
	double score[20];
	string gpa[20];
	double total = 0, avg=0;
	double totalgpa = 0;
	
	for (int i = 0; i < 20; i++) {
		cin >> subject[i] >> score[i] >> gpa[i];
		if (gpa[i] == "A+") {
			total += (score[i] * 4.5);
			totalgpa += score[i];
		}
		else if (gpa[i] == "A0") {
			total += (score[i] * 4.0);
			totalgpa += score[i];
		}
		else if (gpa[i] == "B+") {
			total += (score[i] * 3.5);
			totalgpa += score[i];
		}
		else if (gpa[i] == "B0") {
			total += (score[i] * 3.0);
			totalgpa += score[i];
		}
		else if (gpa[i] == "C+") {
			total += (score[i] * 2.5);
			totalgpa += score[i];
		}
		else if (gpa[i] == "C0") {
			total += (score[i] * 2.0);
			totalgpa += score[i];
		}
		else if (gpa[i] == "D+") {
			total += (score[i] * 1.5);
			totalgpa += score[i];
		}
		else if (gpa[i] == "D0") {
			total += (score[i] * 1.0); 
			totalgpa += score[i];
		}
		else if (gpa[i] == "F") {
			totalgpa += score[i];
		}
		else if (gpa[i] == "P") {
			continue;
		}
	}
	avg = total / totalgpa;
	cout << avg << endl;
	return 0;
}
