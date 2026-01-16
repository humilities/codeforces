//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
//void solve() {
//	int n, k;
//	string str;
//	cin >> n >> k;
//
//	for (int i = 0;i < n;i++) {
//		char ch;
//		cin >> ch;
//		str.push_back(ch);
//	}
//
//	string sub1;
//	string sub2;
//
//	sort(str.begin(), str.end());
//
//	if (k == 1) {
//		cout << str << endl;
//		return;
//	}
//
//	if (str[0] != str[k - 1]) {
//		cout << str[k - 1] << endl;
//		return;
//	}
//
//	if (str[k] != str.back()) {
//		cout << str.substr(k - 1) << endl;
//		return;
//	}
//
//	int extra = (n - k) / k;
//	if ((n - k) % k != 0) {
//		extra++;
//	}
//	cout << str[k - 1] << string(extra, str[k]) << endl;
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