#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<vector<int>> mb(n + 1, vector<int>(26, 0));
  vector<vector<int>> ma(n + 1, vector<int>(26, 0));

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    ma[i][c - 'a']++;

    for (int j = 0; j < 26; j++)
      ma[i][j] += ma[i - 1][j];
  }

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    mb[i][c - 'a']++;

    for (int j = 0; j < 26; j++)
      mb[i][j] += mb[i - 1][j];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    int dif = 0;
    for (int i = 0; i < 26; i++) {
      int ca = ma[r][i] - ma[l - 1][i];
      int cb = mb[r][i] - mb[l - 1][i];

      dif += abs(ca - cb);
    }

    cout << dif / 2 << endl;
  }
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
