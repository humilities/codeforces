#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  if (m < n - 1 || m > 2 * n + 2) {
    cout << "-1" << endl;
    return;
  }

  if (n == m + 1) {
    for (int i = 0; i < m; i++)
      cout << "01";

    cout << "0" << endl;
    return;
  }

  int ex = m - n;
  for (int i = 0; i < n; i++) {
    if (ex)
      cout << "110", ex--;
    else
      cout << "10";
  }

  while (ex) {
    cout << "1";
    ex--;
  }

  cout << endl;
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
