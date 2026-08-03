#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << 1 << "\n";
    return;
  }

  ll ans = 1;
  while (n) {
    int d = n % 10;

    ll me = (ll)(d + 2) * (d + 1) / 2;
    ans *= me;
    n /= 10;
  }

  cout << ans << "\n";
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
