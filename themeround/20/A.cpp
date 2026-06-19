#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  ll r = 1e9;
  ll l = 0;
  ll ans = r;

  while (l <= r) {
    ll k = l + (r - l) / 2;
    ll th = (k + 1) * (k + 1);

    if (th >= n) {
      ans = k;
      r = k - 1;
    } else
      l = k + 1;
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
