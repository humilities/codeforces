#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (int i = 0; i <= 60; i++) {
    ll j = 1LL << i;

    if (j > n)
      break;

    ll co = min(k, n / j);
    ans += co;
    n -= co * j;
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
