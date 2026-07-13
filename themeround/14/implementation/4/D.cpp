#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  int mn = 0;
  lin(i, 0, n) cin >> a[i], mn = max(mn, a[i]);

  ll l = 0;
  ll r = 2e18;

  lin(i, 0, n) {
    ll tar = mn - a[i] - k + 1;
    ll m = 0;

    if (tar)
      m = (tar + 2 * k - 1) / (2 * k);

    ll li = a[i] + 2 * m * k;
    ll ri = a[i] + 2 * m * k + k - 1;

    l = max(l, li);
    r = min(r, ri);
  }

  if (l <= r)
    cout << l << "\n";
  else
    cout << -1 << "\n";
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
