#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll power(ll base, ll exp) {
  ll ans = 1;
  base %= mod;

  while (exp) {
    if (exp & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;

    exp >>= 1;
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;

  int neg1 = 0;
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    if (val > 0)
      pos.push_back(val);
    else
      neg1++;
  }

  ll ans0 = 0;
  ll ans1 = 0;

  if (neg1 == 0) {
    ans0 = 1;
    ans1 = 0;
  } else {
    ll way = power(2, neg1 - 1);

    ans0 = way;
    ans1 = way;
  }

  map<int, ll> dppl;
  map<int, ll> dpmi;
  for (int val : pos) {
    ll pre0 = ans0;
    ll pre1 = ans1;
    ll prepl = dppl[val];
    ll premi0 = dpmi[val];
    ll premi1 = dpmi[val - 1];

    ans0 = (pre0 + prepl + premi1) % mod;
    ans1 = (pre1 + premi0) % mod;
    dppl[val] = (dppl[val] + pre0) % mod;
    dpmi[val] = (dpmi[val] + pre1) % mod;
  }

  cout << ans0 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
