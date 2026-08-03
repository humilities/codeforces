#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int xa, ya;
  int xb, yb;
  int xc, yc;

  cin >> xa >> ya;
  cin >> xb >> yb;
  cin >> xc >> yc;

  int x = 0;
  int y = 0;

  if ((xa < xb && xa < xc) || (xa > xb && xa > xc))
    x = min(abs(xa - xb), abs(xa - xc));

  if ((ya < yb && ya < yc) || (ya > yb && ya > yc))
    y = min(abs(ya - yb), abs(ya - yc));

  cout << x + y + 1 << "\n";
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
