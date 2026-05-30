#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> pre(n + 2, 0);

  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1])
      pre[i] = i - 1;
    else
      pre[i] = pre[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    if (pre[r] < l) {
      cout << -1 << " " << -1 << endl;
      continue;
    } else {
      cout << r << " " << pre[r] << endl;
      continue;
    }
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
