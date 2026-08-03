#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int mn = 1e6 + 5;

ll fac[mn];
ll invfac[mn];
ll d[mn];

ll power(ll base, ll exp) {
  ll res = 1;
  base %= mod;

  while (exp) {
    if (exp & 1)
      res = res * base % mod;

    base = base * base % mod;
    exp >>= 1;
  }

  return res;
}

void pre() {
  d[0] = 1, d[1] = 0;
  for (int i = 2; i < mn; i++)
    d[i] = (i - 1) % mod * ((d[i - 1] + d[i - 2]) % mod) % mod;

  fac[0] = 1;
  for (int i = 1; i < mn; i++)
    fac[i] = i % mod * fac[i - 1] % mod;

  invfac[mn - 1] = power(fac[mn - 1], mod - 2);
  for (int i = mn - 2; i >= 0; i--)
    invfac[i] = invfac[i + 1] % mod * (i + 1) % mod;
}

ll C(ll n, ll k) {
  if (k < 0 || k > n)
    return 0;
  return fac[n] % mod * invfac[k] % mod * invfac[n - k] % mod;
}

void solve() {
  int n, m;
  cin >> n >> m;

  if (m > n) {
    cout << 0 << "\n";
    return;
  }

  cout << C(n, m) * d[n - m] % mod << "\n";
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
