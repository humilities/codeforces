#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int mn = a[0];
  int th = 0;
  ll ans = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] >= mn)
      mn = max(mn, a[i]);
    else {
      ans += mn - a[i];
      th = max(th, mn - a[i]);
    }
  }

  cout << ans + th << "\n";
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
