#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> gra(n + 1, vector<int>(m + 1));

  vector<int> row(n + 1);
  vector<int> col(m + 1);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> gra[i][j];

      if (gra[i][j] == 0) {
        row[i] = 1;
        col[j] = 1;
      }
    }

  vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (gra[i][j] == 0)
        continue;

      if (gra[i][j] == 1 && row[i] == 1 && col[j] == 1) {
        cout << "NO" << endl;
        return;
      } else if (row[i] == 0 && col[j] == 0)
        ans[i][j] = 1;

      // cout << i << " " << j << endl;
      // cout << row[i] << " " << col[j] << endl;
      //  cout << ans[i][j] << endl;
    }

    // cout << endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int jud = 0;

      for (int k = 1; k <= m; k++)
        if (ans[i][k] == 1) {
          jud = 1;
          break;
        }
      for (int k = 1; k <= n; k++)
        if (ans[k][j] == 1) {
          jud = 1;
          break;
        }

      if (jud != gra[i][j]) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j] << " \n"[j == m && i != n];
    }
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
