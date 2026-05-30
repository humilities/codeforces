#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> p;
  for (int i = 1; i < n; i += 2)
    p.push_back(i);
  for (int i = 0; i < n; i += 2)
    p.push_back(i);

  vector<vector<int>> ans(n, vector<int>(m, 0));
  int cnt = 1;

  lin(i, 0, p.size()) {
    int row = p[i];
    lin(j, 0, m) ans[row][j] = cnt++;
  }

  lin(i, 0, n) lin(j, 0, m) cout << ans[i][j] << " \n"[j == m - 1];

  return;
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
