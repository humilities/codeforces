#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid[i];

  vector<string> ans = grid;
  for (int i = 0; i < n; i++) {
    int flag = 0;

    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'U') {
        if (flag == 0) {
          ans[i][j] = 'B';
          ans[i + 1][j] = 'W';
        } else {
          ans[i][j] = 'W';
          ans[i + 1][j] = 'B';
        }

        flag ^= 1;
      }
    }

    if (flag != 0) {
      cout << -1 << "\n";
      return;
    }
  }

  for (int j = 0; j < m; j++) {
    int flag = 0;

    for (int i = 0; i < n; i++) {
      if (grid[i][j] == 'L') {
        if (flag == 0) {
          ans[i][j] = 'B';
          ans[i][j + 1] = 'W';
        } else {
          ans[i][j] = 'W';
          ans[i][j + 1] = 'B';
        }

        flag ^= 1;
      }
    }

    if (flag != 0) {
      cout << -1 << "\n";
      return;
    }
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << "\n";
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
