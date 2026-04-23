#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

ll count0(ll n) {
    if (n < 0) return 0;
    ll count = 1;
    if (n >= 3) {
        count += (n - 3) / 4 + 1;
    }
    return count;
}

ll count1(ll n) {
    if (n < 1) return 0;
    return (n - 1) / 4 + 1;
}

void solve() {
    ll n, x;
    cin >> n >> x;

    ll L0 = count0(x - 1);
    ll L1 = count1(x - 1);

    ll R0 = count0(n) - L0;
    ll R1 = count1(n) - L1;

    ll ans = ((L0 % MOD) * (R0 % MOD)) % MOD;
    ans = (ans + (L1 % MOD) * (R1 % MOD)) % MOD;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}