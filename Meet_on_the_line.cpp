//#include<iostream>
//#include<vector>
//#include <iomanip>
//
//using namespace std;
//
//void solve() {
//	int n;
//	long long min1 = INT_MAX;
//	long long max1 = INT_MIN;
//	cin >> n;
//
//	vector<int> x(n);
//	vector<int> dre(n);
//
//	for (int i = 0;i < n;i++) {
//		cin >> x[i];
//	}
//
//	for (int i = 0;i < n;i++) {
//		cin >> dre[i];
//	}
//
//	for (int i = 0;i < n;i++) {
//		min1 = min(min1, (long long)(x[i] - dre[i]));
//		max1 = max(max1, (long long)(x[i] + dre[i]));
//	}
//
//	cout << fixed << setprecision(6) << (min1 + max1) / 2.0 << endl;
//	//cout << (min1 + max1) / 2.0 << endl;
//}
//
//int main() {
//	int t;
//	cin >> t;
//
//	while (t--) {
//		solve();
//	}
//
//	return 0;
//}