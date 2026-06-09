#include <bits/stdc++.h>

using namespace std;

int luc(int x) {
  int mn = 9, mx = 0;

  while (x > 0) {
    int d = x % 10;
    mn = min(mn, d);
    mx = max(mx, d);
    x /= 10;
  }

  return mx - mn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int l, r;
    cin >> l >> r;

    int ans = l;
    int bes = luc(l);

    for (int x = l; x <= r && x <= l + 100; x++) {
      int cur = luc(x);

      if (cur > bes) {
        bes = cur;
        ans = x;
      }

      if (bes == 9)
        break;
    }

    cout << ans << '\n';
  }

  return 0;
}
