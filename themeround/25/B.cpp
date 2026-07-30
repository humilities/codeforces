#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

ll pw(ll base, ll exp) {
  ll ret = 1;
  base %= mod;

  while (exp) {
    if (exp & 1)
      ret = (base * ret) % mod;

    base = (base * base) % mod;
    exp >>= 1;
  }

  return ret;
}

void solve() {
  int n;
  cin >> n;

  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> q[i];

  vector<int> p1(n);
  vector<int> p2(n);
  int idx1 = 0, idx2 = 0;
  p1[0] = 0, p2[0] = 0;

  for (int i = 1; i < n; i++) {
    if (p[i] > p[idx1]) {
      p1[i] = i;
      idx1 = i;
    } else
      p1[i] = idx1;

    if (q[i] > q[idx2]) {
      p2[i] = i;
      idx2 = i;
    } else
      p2[i] = idx2;
  }

  vector<ll> ans(n);
  for (int i = 0; i < n; i++) {
    int j1 = p1[i];
    int j2 = i - p2[i];

    pair<int, int> val1 = {max(p[j1], q[i - j1]), min(p[j1], q[i - j1])};
    pair<int, int> val2 = {max(p[j2], q[i - j2]), min(p[j2], q[i - j2])};

    int bes;
    if (val1 >= val2)
      bes = j1;
    else
      bes = j2;

    ans[i] = (pw(2, p[bes]) + pw(2, q[i - bes])) % mod;
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
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
