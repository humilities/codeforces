#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> b(n);
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;

    for (int j = 0; j < l; j++)
      cin >> b[i][j];
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
