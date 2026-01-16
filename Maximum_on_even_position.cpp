//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		ll base = 0;
//		cin >> n;
//
//		vector<ll> a(n);
//		for (int i = 0;i < n;i++) {
//			cin >> a[i];
//
//			if (i% 2 == 0) {
//				base += a[i];
//			}
//		}
//
//		ll gain = 0;
//		vector<ll> x, y;
//
//		for (int i = 0;i < n - 1;i += 2) {
//			x.push_back(a[i + 1] - a[i]);
//		}
//
//		for (int i = 1;i < n - 1;i += 2) {
//			y.push_back(a[i] - a[i + 1]);
//		}
//
//		auto maxSubary = [](vector<ll>& v) {
//			ll best=0, cur=0;
//
//			for (ll node : v) {
//				cur = max(node, cur + node);
//				best = max(best, cur);
//			}
//
//			return best;
//			};
//
//		gain = max(0ll, max(maxSubary(x), maxSubary(y)));
//
//		cout << base + gain << endl;
//	}
//
//	return 0;
//}