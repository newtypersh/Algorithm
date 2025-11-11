#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {
		vector<int> row;
		for (int j = 0; j < arr2[0].size(); j++) {
			int row_tmp = 0;
			for (int k = 0; k < arr1[i].size(); k++) {
				row_tmp += arr1[i][k] * arr2[k][j];
			}
			row.push_back(row_tmp);
		}
		answer.push_back(row);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> v1;
	vector<vector<int>> v2;


	int num;
	int n, m, k;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> vv1;
		for (int j = 0; j < m; j++) {
			cin >> num;
			vv1.push_back(num);
		}
		v1.push_back(vv1);
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		vector<int> vv2;
		for (int j = 0; j < k; j++) {
			cin >> num;
			vv2.push_back(num);
		}
		v2.push_back(vv2);
	}

	vector<vector<int>> ans = solution(v1, v2);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}