#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int type, n, m, p;
  cin >> type >> n >> m >> p;

  ll ans = 1;
  ll sta = n - m + 1;

  lin(i, 0, m) ans = ans * (sta - i) % p;

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
