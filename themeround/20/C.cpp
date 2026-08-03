#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;

  n %= m;
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }

  ll ans = 0;
  ll g = gcd(n, m);
  ll m1 = m / g;

  if ((m1 & (m1 - 1)) != 0) {
    cout << -1 << "\n";
    return;
  }

  while (n) {
    ans += n;
    n *= 2;
    n %= m;
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
