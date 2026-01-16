//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//const int N = 2e5 + 10;
//typedef long long ll;
//
//ll n, k;
//ll num[N];
//
//int check(ll op) {
//	ll sum = 0;
//
//	for (int i = 0;i <= min(n - 1, op);i++) {
//		sum += num[i];
//
//		if ((sum - 1ll*(num[n] - op + i) * i + op - i) >= k) {
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//void solve() {
//	cin >> n >> k;
//	ll cnt = 0;
//	
//	for (int i = 1;i <= n;i++) {
//		cin >> num[i];
//		cnt += num[i];
//	}
//
//	k = cnt - k;
//	if (k <= 0) {
//		cout << 0 << endl;
//		return;
//	}
//
//	sort(num+1, num + n+1, greater<int>());
//
//	ll l = 1, r = n - 1 + num[n];
//
//	while (l <= r) {
//		ll mid = l + (r - l) / 2;
//
//		if (check(mid)) {
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//
//	cout << l << endl;
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