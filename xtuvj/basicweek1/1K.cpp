#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

int n, m;

int a[maxn][maxn];
bool can[maxn][maxn];
vector<int> rou[maxn][maxn];

bool limit(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

void solve() {
  cin >> n >> m;

  if (n < 3 || m < 3) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      can[i][j] = true;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;

      if (ch != '\n')
        a[i][j] = ch;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (abs(dx) + abs(dy) == 0 || !limit(i + dx, j + dy))
            continue;

          if (a[i][j] == '.')
            can[i + dx][j + dy] = false;
          else if (i + dx != 0 && i + dx != n - 1 && j + dy != 0 &&
                   j + dy != m - 1)
            rou[i][j].push_back((i + dx) * m + j + dy);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.')
        continue;

      bool flag = false;
      for (const int val : rou[i][j]) {
        int dx = val / m;
        int dy = val % m;

        if (can[dx][dy])
          flag = true;
      }

      if (!flag) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
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
