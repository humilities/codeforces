//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<climits>
//
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//
//	vector<int> num(n);
//	vector<int> p, q;
//	for (int i = 0;i < n;i++) {
//		cin >> num[i];
//
//		if (num[i] == 1) {
//			p.push_back(i + 1);
//		}
//		else {
//			q.push_back(i + 1);
//		}
//	}
//
//	int k = p.size();
//	int m = q.size();
//	vector<vector<int>> dp(k + 1, vector<int>(m + 1, INT_MAX/2));
//
//	dp[0][0] = 0;
//	for (int j = 0; j <= m; j++) {
//		dp[0][j] = 0;
//	}
//
//	for (int i = 1;i <= k;i++) {
//		for (int j = i;j <= m;j++) {
//			//dp[0][j] = 0;
//
//			int op1 = dp[i - 1][j - 1] + abs(q[j-1] - p[i-1]);
//
//			int op2 = dp[i][j - 1];
//
//			dp[i][j] = min(op1, op2);
//		}
//	}
//
//	cout << dp[k][m] << endl;
//	return 0;
//}