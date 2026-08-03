#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;

  int rem = (x + y) % 3;

  if (rem == 0 && (-x / 4) <= y && y <= x / 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
