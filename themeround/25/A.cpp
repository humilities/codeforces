#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> a;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int r, int c) {
  int sum = a[r][c];
  a[r][c] = 0;

  for (int i = 0; i < 4; i++) {
    int nx = r + dx[i];
    int ny = c + dy[i];

    if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] > 0)
      sum += dfs(nx, ny);
  }

  return sum;
}

void solve() {
  cin >> n >> m;
  a.assign(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] > 0)
        ans = max(ans, dfs(i, j));

  cout << ans << "\n";
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
