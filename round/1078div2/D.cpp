#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  int n, m;
  ll tol = 0;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  vector<int> row(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == 1) {
        tol++;
        row[i]++;
      }
    }
  }

  ll k = tol / 2;
  cout << 1LL * k * (tol - k) << endl;

  ll sr = -1;
  ll cur = 0;
  for (int i = 0; i < n; i++) {
    if (cur + row[i] <= tol / 2) {
      sr++;
      cur += row[i];
    } else {
      break;
    }
  }

  int sl = m;
  ll nee = k - cur;
  ll cnt = 0;
  if (sr + 1 < n && nee > 0) {
    for (int j = m - 1; j >= 0; j--) {
      if (grid[sr + 1][j] == 1) {
        cnt++;
      }
      if (cnt == nee) {
        sl = j;
        break;
      }
    }
  }

  string str = "";
  for (int i = 0; i <= sr; i++)
    str += "D";
  for (int i = 0; i < sl; i++)
    str += "R";
  if (sr + 1 < n)
    str += "D";

  for (int i = sl; i < m; i++)
    str += "R";
  while (str.size() < n + m)
    str += "D";

  cout << str << endl;
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
