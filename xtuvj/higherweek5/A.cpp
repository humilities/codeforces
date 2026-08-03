#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007;

ll power(ll base, ll exp) {
  ll ret = 1;
  base %= mod;

  while (exp) {
    if (exp & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;

    exp >>= 1;
  }

  return ret;
}

ll on(ll n) { return power(n, mod - 2); }

ll A(const vector<ll> &fac, int i, int j) {
  if (j < 0 || j > i)
    return 0;
  return fac[i] * on(fac[j]) % mod * on(fac[i - j]) % mod;
}

void solve() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  int mn = 2 * n;
  vector<ll> fac(mn + 1, 1);
  lin(i, 2, mn + 1) fac[i] = (fac[i - 1] * i) % mod;

  ll cnt = A(fac, 2 * n - 1, n);
  ll ans = (2 * cnt - n) % mod;

  if (ans < 0)
    ans += mod;
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
