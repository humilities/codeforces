#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, r, ag;
  cin >> n >> r >> ag;

  ll sum = (ll)n * ag;

  vector<int> a(n), b(n);
  // map<int, int> ma;
  vector<pair<int, int>> ma;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    sum -= val;
    a[i] = (r - val) < 0 ? 0 : (r - val);

    cin >> b[i];
    ma.push_back({b[i], a[i]});
  }

  sort(ma.begin(), ma.end());

  ll ans = 0;
  for (auto const &[key, val] : ma) {
    if (sum <= 0)
      break;
    if (val == 0)
      continue;

    ll nee = min(sum, (ll)val);

    ans += (ll)nee * key;
    sum -= nee;
  }

  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
