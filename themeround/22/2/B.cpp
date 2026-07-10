#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  ll x, y;
  cin >> n >> x >> y;

  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll m1 = sum - y;
  ll m2 = sum - x;

  sort(a.begin(), a.end());

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll val = m1 - a[i];
    ll var = m2 - a[i];

    auto sta = a.begin() + i + 1;

    int l = lower_bound(sta, a.end(), val) - a.begin();
    int r = upper_bound(sta, a.end(), var) - a.begin();

    ans += (r - l);
  }

  cout << ans << "\n";
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
