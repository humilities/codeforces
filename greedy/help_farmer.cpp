//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    ll n;
//    cin >> n;
//
//    vector<ll> divisors;
//    for (ll i = 1; i * i <= n; i++) {
//        if (n % i == 0) {
//            divisors.push_back(i);
//            if (i != n / i) {
//                divisors.push_back(n / i);
//            }
//        }
//    }
//
//    ll min_stolen = LLONG_MAX;
//    ll max_stolen = 0;
//
//    for (ll d : divisors) {
//        ll m1 = n / d;
//        for (ll e = 1; e * e <= m1; e++) {
//            if (m1 % e == 0) {
//                ll k = m1 / e;
//                ll A = k + 1;
//                ll B = d + 2;
//                ll C = e + 2;
//                ll original = A * B * C;
//                ll stolen = original - n;
//                if (A >= 2 && B >= 3 && C >= 3) {
//                    min_stolen = min(min_stolen, stolen);
//                    max_stolen = max(max_stolen, stolen);
//                }
//
//                // Also swap e and the other divisor
//                ll e2 = m1 / e;
//                if (e2 != e) {
//                    k = m1 / e2; // = e
//                    A = k + 1;
//                    B = d + 2;
//                    C = e2 + 2;
//                    original = A * B * C;
//                    stolen = original - n;
//                    if (A >= 2 && B >= 3 && C >= 3) {
//                        min_stolen = min(min_stolen, stolen);
//                        max_stolen = max(max_stolen, stolen);
//                    }
//                }
//            }
//        }
//    }
//
//    cout << min_stolen << " " << max_stolen << endl;
//
//    return 0;
//}