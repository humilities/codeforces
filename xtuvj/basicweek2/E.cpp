#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m;
  cin >> m;

  vector<vector<int>> gra(2, vector<int>(m));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++)
      cin >> gra[i][j];
  }

  if (m == 1) {
    cout << 0 << "\n";
    return;
  }

  vector<int> pre(m);
  vector<int> suf(m);

  pre[0] = gra[0][0];
  for (int i = 1; i < m; i++)
    pre[i] = pre[i - 1] + gra[0][i];

  suf[m - 1] = gra[1][m - 1];
  for (int i = m - 2; i >= 0; i--)
    suf[i] = suf[i + 1] + gra[1][i];

  int ans = 2e9;
  int pos = 0;
  for (int i = 0; i < m; i++) {
    int p1 = suf[0] - suf[i];
    int s1 = pre[m - 1] - pre[i];

    int val = max(p1, s1);
    if (val < ans) {
      ans = val;
      pos = i;
    }
  }

  // cout << pos << endl;

  int re = pre[m - 1] - pre[pos];
  int su = suf[0] - suf[pos];

  cout << max(re, su) << "\n";
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
