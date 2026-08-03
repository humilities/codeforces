#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int x, y, k;
  cin >> x >> y >> k;

  int ix = (x + k - 1) / k;
  int iy = (y + k - 1) / k;

  if (ix > iy)
    cout << 2 * ix - 1 << "\n";
  else
    cout << 2 * iy << "\n";
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
