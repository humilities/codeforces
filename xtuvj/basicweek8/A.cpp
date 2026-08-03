#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;

  map<int, int> lc, rc;
  for (int i = 0; i < l; i++) {
    int c;
    cin >> c;
    lc[c]++;
  }
  for (int i = 0; i < r; i++) {
    int c;
    cin >> c;
    rc[c]++;
  }

  for (auto &[c, cnt] : lc) {
    int th = min(cnt, rc[c]);
    cnt -= th;
    rc[c] -= th;

    l -= th;
    r -= th;
  }

  if (l < r) {
    swap(l, r);
    swap(lc, rc);
  }

  int cost = 0;

  for (auto &[c, cnt] : lc) {
    if (l <= r)
      break;
    if (cnt >= 2) {
      int flip = min(cnt / 2, (l - r) / 2);
      cost += flip;
      cnt -= flip * 2;
      l -= flip * 2;
    }
  }

  int flip = (l - r) / 2;
  cost += flip;
  l -= flip;
  r += flip;

  cost += l;

  cout << cost << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
}
