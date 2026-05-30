#include <bits/stdc++.h>

using namespace std;
// pedef long long ll;
#define int long long

bool get(int x, int a, int lim) {
  int f = 0;
  for (int i = 59; i >= 0; i--) {
    f <<= 1;
    if (((x >> i) & 1) == 1) {
      f++;
    }
    if (((a >> i) & 1) == 1) {
      f -= min(lim, f);
    }
  }
  return (f == 0);
}

void solve() {
  int x, a;
  cin >> x >> a;

  if (!get(x, a, 1ll << 60)) {
    cout << -1 << '\n';
    return;
  }

  int l = 0, r = (1ll << 60);
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (get(x, a, m)) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << l << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
