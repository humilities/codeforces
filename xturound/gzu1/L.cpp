#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int y = 0;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    y = i;

    int x = n - 3 * y;
    x /= 2;

    if (x > 2 * y + 1)
      x = 2 * y + 1;

    ans = max(ans, x + y);
  }

  cout << ans << endl;
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
