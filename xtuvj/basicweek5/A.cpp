#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);
  lin(i, 0, n) cin >> a[i];
  lin(i, 0, n) cin >> b[i];

  vector<pair<int, int>> ma;
  lin(i, 0, n) ma.push_back({a[i], b[i]});
  sort(ma.begin(), ma.end(), greater<>());

  ll sum = 0;
  ll ans = 1e18;
  lin(i, 0, n) ans = min(ans, max((ll)ma[i].first, sum)), sum += ma[i].second;

  ans = min(ans, sum);

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
