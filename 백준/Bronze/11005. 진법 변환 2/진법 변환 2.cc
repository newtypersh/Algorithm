//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    string b_num;
//    int n;
//    cin >> b_num >> n;
//
//    int sum(0);
//    for (int i = 0; i < b_num.length(); i++)
//    {
//        int tmp = b_num[b_num.length() - (i + 1)];
//        if ('0' <= tmp && tmp <= '9')
//        {
//            tmp = tmp - '0';
//        }
//        else
//        {
//            tmp = tmp + 10 - 'A';
//        }
//        sum += (tmp * (int)pow(n, i));
//    }
//    cout << sum << '\n';
//
//    return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;

//void reverse(string* total) {
//	string tmp = *total;
//	int size = tmp.length();
//	for (int i = 0; i < size/2; i++) {
//		string tmp = *(total + size - i);
//		*(total + size - i) = *(total + i);
//		*(total + i) = tmp;
//	}
//}

int main() {
	int N, B;
	string total;
	cin >> N >> B;
	char A;
	while (N != 0) {
		if ((N % B) >= 10) {
			A = (N % B) + 55;
			total += A;
		}
		else {
			A = (N%B)+48;
			total += A;
		}
		N /= B;
	}

	//reverse(&total);

	reverse(total.begin(), total.end());

	cout << total << "\n";


	return 0;
}