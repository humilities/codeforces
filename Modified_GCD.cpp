//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//
//vector<int> getdiv(int g) {
//	vector<int> ret;
//
//	for (int i = 1;i * i <= g;i++) {
//
//		if (g % i == 0) {
//			ret.push_back(i);
//			
//			if (i != g / i) {
//				ret.push_back(g / i);
//			}
//		}
//	}
//
//	sort(ret.begin(), ret.end());
//
//	return ret;
//}
//
//int main() {
//	int a, b;
//	cin >> a >> b;
//
//	int q;
//	cin >> q;
//
//	int g = gcd(a, b);
//	vector<int> divis = getdiv(g);
//
//	while (q--) {
//		int l, r;
//		cin >> l >> r;
//
//		auto it = upper_bound(divis.begin(), divis.end(), r);
//
//		if (it < divis.begin()) {
//			cout << -1 << endl;
//		}
//		else {
//			--it;
//			int d = *it;
//
//			if (l <= d && d <= r) {
//				cout << d << endl;
//			}
//			else {
//				cout << -1 << endl;
//			}
//		}
//	}
//
//	return 0;
//}