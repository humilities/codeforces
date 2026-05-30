#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  map<int, int> ma;
  lin(i, 0, n) cin >> a[i], ma[a[i]]++;

  map<int, int> lim;
  for (auto const &[val, seq] : ma) {
    if (seq % k != 0) {
      cout << 0 << "\n";
      return;
    }
    lim[val] = seq / k;
  }

  ll ans = 0;
  map<int, int> cur;
  int l = 0;

  for (int r = 0; r < n; r++) {
    cur[a[r]]++;

    while (cur[a[r]] > lim[a[r]])
      cur[a[l]]--, l++;
    ans += (r - l + 1);
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
