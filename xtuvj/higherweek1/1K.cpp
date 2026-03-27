#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int mx = 0, mn = 1e9;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }

  if (mx - mn > k) {
    cout << "NO" << endl;
    return;
  }

  vector<vector<int>> ans(n, vector<int>());
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    int idx = 0;

    while (a[i]) {
      if (idx <= mx - k)
        ans[i].push_back(1), idx++;
      else
        ans[i].push_back(++cnt);

      a[i]--;

      // cout << cnt << " ";
    }
  }

  // cout << endl;

  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (const int val : ans[i]) {
      cout << val << " ";
    }
    cout << endl;
  }
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
