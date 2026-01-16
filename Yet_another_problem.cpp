//#include<iostream>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//int q;
//
//ll gcd(ll a, ll b) {
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//
//void solve() {
//	int a, b;
//	int cnt = 0;
//	cin >> a >> b >> q;
//
//	ll lcm = a * (b / gcd(a, b));
//	vector<ll> pre(lcm+2,0);
//
//	for (int i = 1;i <= lcm;i++) {
//		if ((i % a) % b != (i % b) % a) {
//			cnt++;
//		}
//
//		pre[i + 1] = pre[i] + ((i % a) % b != (i % b) % a);
//	}
//
//	vector<ll> ret;
//	while (q--) {
//		ll l, r;
//		cin >> l >> r;
//
//		auto count = [&](ll n) {
//			if (n < 0) return 0ll;
//			return (n / lcm) * cnt + pre[n % lcm+1];
//			};
//
//		ret.push_back(count(r)-count(l-1));
//	}
//
//	for (int i = 0;i < ret.size();i++) {
//		cout << ret[i] << " ";
//	}
//
//	cout << endl;
//}
//
//int main() {
//	int t;
//	cin >> t;
//
//	while (t--) {
//		solve();
//		//cout << endl;
//	}
//	return 0;
//}