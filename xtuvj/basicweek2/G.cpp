#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x, m;
  cin >> n >> x >> m;

  int i = x, j = x;
  while (m--) {
    int l, r;
    cin >> l >> r;

    if (max(l, i) <= min(r, j)) {
      i = min(i, l);
      j = max(j, r);
    }
  }
  // cout << i << " " << j << endl;

  cout << j - i + 1 << endl;
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
