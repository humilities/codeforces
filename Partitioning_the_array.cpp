//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<numeric>
//#include<cmath>
//
//using namespace std;
//
//typedef long long ll;
//
//ll gcd(ll a, ll b) {
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//
//void solve() {
//	int n;
//	int ans = 0;
//	cin >> n;
//
//	vector<ll> a(n);
//
//	for (int i = 0;i < n;i++) {
//		cin >> a[i];
//	}
//
//	vector<int> divisor;
//	for (int i = 1;i <= n;i++) {
//		if (n % i == 0) {
//			divisor.push_back(i);
//		}
//	}
//
//	for (int k : divisor) {
//		vector<ll> g(k, 0);
//
//		for (int i = 0;i < k;i++) {
//			ll prev = a[i];
//
//			for (int j = i + k;j < n;j += k) {
//				ll diff = abs(prev - a[j]);
//
//				if (g[i] == 0) {
//					g[i] = diff;
//				}
//				else {
//					g[i] = gcd(g[i], diff);
//				}
//
//				prev = a[j];
//			}
//		}
//
//		ll G = 0;
//		for (int i = 0;i < k;i++) {
//			if (g[i] == 0) {
//				continue;
//			}
//			if (G == 0) {
//				G = g[i];
//			}
//			else {
//				G = gcd(G, g[i]);
//			}
//		}
//
//		if (G != 1) {
//			ans++;
//		}
//	}
//	cout << ans << endl;
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