#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int luc(int n) {
  int mm = 0, mn = 9;

  while (n) {
    int val = n % 10;
    mm = max(mm, val);
    mn = min(mn, val);

    n /= 10;
  }

  return mm - mn;
}

void solve() {
  int l, r;
  cin >> l >> r;

  if (r - l > 100) {
    int k = (l / 100) * 100 + 90;
    cout << k << "\n";
  } else {
    int na = 0;
    int ans = 0;

    for (int i = l; i <= r; i++) {
      int num = luc(i);

      if (num > na) {
        na = num;
        ans = i;
      }
    }

    cout << ans << "\n";
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
