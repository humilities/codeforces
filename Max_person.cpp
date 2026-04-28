//106208C

//#include<iostream>
//#include<vector>
//
//using namespace std;
//typedef long long ll;
//
//void solve() {
//	ll n, m;
//	cin >> n >> m;
//
//	if (m % 2 == 1) {
//		cout << -1 << endl;
//		return;
//	}
//
//	ll m_pri=m/2;
//	ll ans=0;
//
//	while (m_pri) {
//		ll r = m_pri % 2;
//		ll afford = min(n, m_pri);
//
//		ll use = afford;
//		if (afford % 2 != r) {
//			use--;
//		}
//
//		if (use < r) {
//			cout << -1 << endl;
//			return;
//		}
//
//		ans += use;
//		m_pri = (m_pri - use) / 2;
//	}
//
//	cout << ans << endl;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int t;
//	cin >> t;
//
//	while (t--) {
//		solve();
//	}
//
//	return 0;
//}