#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int x, y;
  cin >> x >> y;

  if (x == y) {
    cout << -1 << "\n";
    return;
  }

  ll p = 1;
  int mx = max(x, y);
  while (p <= mx)
    p <<= 1;

  cout << p - mx << "\n";
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
