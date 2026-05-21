#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll power(ll base, ll exp) {
  ll ret = 1;

  while (exp) {
    if (exp & 1)
      ret = ret * base % mod;

    base = (base * base) % mod;
    exp >>= 1;
  }

  return ret;
}

ll inv(ll n) { return power(n, mod - 2); }

void pre(ll mn, vector<ll> &fac, vector<ll> &invfac) {
  fac[0] = 1;
  invfac[0] = 1;

  lin(i, 1, mn + 1) fac[i] = (fac[i - 1] * i) % mod;
  invfac[mn] = inv(fac[mn]);
  for (int i = mn - 1; i >= 1; i--)
    invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
}

ll nC(ll n, ll k, const vector<ll> &fac, const vector<ll> &invfac) {
  if (k < 0 || k > n)
    return 0;
  return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  ll sum = 0;
  lin(i, 0, m) {
    int num;
    cin >> num;

    sum += num;
  }

  ll rem = n - sum;
  if (rem < m) {
    cout << 0;
    return;
  }

  ll r = rem - 1;
  ll l = m - 1;

  vector<ll> fac(r + 1);
  vector<ll> invfac(r + 1);

  pre(r, fac, invfac);

  cout << nC(r, l, fac, invfac);
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
