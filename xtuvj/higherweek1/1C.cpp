#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  int ans = 0;
  double div = (double)n / 2;

  if (m < div)
    ans = m + 1;
  else if (m > div)
    ans = m - 1;
  else
    ans = m + 1;

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
