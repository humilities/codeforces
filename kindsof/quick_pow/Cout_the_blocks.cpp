//#include <stdio.h>
// 
// 1327E
//#include <stdlib.h>
//typedef long long ll;
//const int MOD = 998244353;
//
//ll qpow(ll base, ll exp) {
//    ll res = 1;
//    base %= MOD;
//    while (exp > 0) {
//        if (exp & 1) res = res * base % MOD;
//        base = base * base % MOD;
//        exp >>= 1;
//    }
//    return res;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    for (int i = 1; i <= n; ++i) {
//        ll ans;
//        if (i == n) {
//            ans = 10;
//        }
//        else {
//            ll term1 = (n - i - 1 > 0) ?
//                (ll)(n - i - 1) * 10 % MOD * 81 % MOD * qpow(10, n - i - 2) % MOD : 0;
//            ll term2 = 2LL * 10 % MOD * 9 % MOD * qpow(10, n - i - 1) % MOD;
//            ans = (term1 + term2) % MOD;
//        }
//        printf("%lld%c", ans, i == n ? '\n' : ' ');
//    }
//
//    return 0;
//}