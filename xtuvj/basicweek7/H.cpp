#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, c, q;
  cin >> n >> c >> q;

  ll len = n;
  vector<ll> st(c);
  vector<ll> ed(c);

  vector<ll> oi(c);
  string s;
  cin >> s;

  lin(i, 0, c) {
    ll l, r;
    cin >> l >> r;

    st[i] = len + 1;
    ed[i] = len + (r - l + 1);
    oi[i] = l;

    len = ed[i];
  }

  while (q--) {
    ll k;
    cin >> k;

    for (int i = c - 1; i >= 0; i--) {
      if (k >= st[i] && k <= ed[i]) {
        ll of = k - st[i];
        k = oi[i] + of;
      }
    }

    cout << s[k - 1] << "\n";
  }
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
