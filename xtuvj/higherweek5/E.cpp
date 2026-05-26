#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 1e7 + 9;
const int mn = 1e6;

int dp[mn];
ll fav[mn];
ll invfav[mn];

ll power(ll base, ll exp) {
  ll res = 1;
  base %= mod;

  while (exp) {
    if (exp & 1)
      res = (res * base) % mod;

    base *= base;
    exp >>= 1;
  }

  return base;
}

ll iv(ll num) { return power(num, mod - 2); }

void pre() {
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= mn; i++)
    dp[i] = (i - 1) % mod * (dp[i - 1] + dp[i - 2]);
  for (int i = 1; i <= mn; i++)
    fav[i] = fav[i - 1] % mod * i;
}

ll C(ll n, ll k) {
  return fav[n] % mod * invfav[n - k] % mod * invfav[k] % mod;
}

void solve() {
  int n, m;
  cin >> n >> m;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += C(n, i) * dp[i] % mod;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
