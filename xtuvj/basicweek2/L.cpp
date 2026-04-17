#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;
  map<pair<int, int>, int> ma;
  for (int i = 0; i < n; i++) {
    ll fx = a[i] % x;
    ll fy = a[i] % y;

    ll tx = (x - fx) % x;
    ll ty = fy;

    if (ma.count({tx, ty}))
      ans += ma[{tx, ty}];

    ma[{fx, fy}]++;
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
