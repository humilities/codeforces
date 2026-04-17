//#include<iostream>
//#include<vector>
//
//typedef long long ll;
//using namespace std;
//const ll mod = 1e9 + 7;
//bool vis[mod];
//
//ll f(ll i) {
//	if (i == 1) return 2;
//
//	ll x = 2;
//	while (i % x == 0) {
//		if (vis[x]) {
//			continue;
//		}
//
//		x++;
//		vis[x] = true;
//
//		for (ll y = 2;y <= x;y++) {
//			vis[y * x] = true;
//		}
//	}
//
//	return x;
//}
//
//void solve() {
//	ll n;
//	ll sum = 0;
//	cin >> n;
//
//	for (ll i = 1;i <= n;i++) {
//		sum = (sum + f(i)) % mod;
//	}
//
//	cout << sum << endl;
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

//#include <iostream>
//#include <numeric> 
//using namespace std;
//
//typedef long long ll;
//const ll MOD = 1e9 + 7;
//
//ll gcd(ll a, ll b) {
//    return b == 0 ? a : gcd(b, a % b);
//}
//
//ll lcm(ll a, ll b) {
//    return a / gcd(a, b) * b;
//}
//
//ll calculate_sum(ll n) {
//    ll sum = 0;
//    ll lcm_prev = 1;
//
//    for (ll k = 2; ; k++) {
//        ll lcm_k = lcm(lcm_prev, k); 
//
//        if (lcm_prev > n) {
//            break;
//        }
//
//        ll cnt = (n / lcm_prev) - (n / lcm_k);
//
//        sum = (sum + cnt * k) % MOD;
//
//        lcm_prev = lcm_k;
//    }
//
//    return sum;
//}
//
//int main() {
//    ios::sync_with_stdio(false); 
//    cin.tie(nullptr);
//
//    int t; 
//    cin >> t;
//
//    while (t--) {
//        ll n;
//        cin >> n; 
//        cout << calculate_sum(n) << "\n"; 
//    }
//
//    return 0;
//}