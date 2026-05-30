#include <bits/stdc++.h>

using namespace std;

vector<string> s;
int n, m;

bool can(int r, int c) {
  if (s[r][c] == '.')
    return false;

  for (int i = r - 1; i <= r; i++) {
    for (int j = c - 1; j <= c; j++) {
      if (i < 0 || i + 1 >= n || j < 0 || j + 1 >= m)
        continue;

      int cnt = 0;
      if (s[i][j] == '.')
        cnt++;
      if (s[i + 1][j] == '.')
        cnt++;
      if (s[i + 1][j + 1] == '.')
        cnt++;
      if (s[i][j + 1] == '.')
        cnt++;

      if (cnt == 3)
        return true;
    }
  }

  return false;
}

void solve() {
  cin >> n >> m;

  s.resize(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];

  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (can(i, j)) {
        s[i][j] = '.';
        q.push({i, j});
      }
    }
  }

  int dx[] = {
      -1, -1, -1, 0, 0, 1, 1, 1,
  };
  int dy[] = {-1, 0, 1, 1, -1, -1, 0, 1};

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && can(nx, ny)) {
        q.push({nx, ny});
        s[nx][ny] = '.';
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << s[i] << "\n";
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
