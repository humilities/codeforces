#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  int mn = 1e9;
  int mx = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }

  vector<int> b = a;
  sort(b.begin(), b.end());

  bool is = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      is = false;
      break;
    }
  }

  if (is) {
    cout << -1 << endl;
    return;
  } else {
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        int cur = max(mx - a[i], a[i] - mn);
        ans = min(cur, ans);
      }
    }

    cout << ans << endl;
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
