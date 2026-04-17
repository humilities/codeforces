#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;

  if (k == 1)
    cout << n << endl;
  else {
    ll ans = 1;

    while (ans < n) {
      ans = (ans << 1) | 1;
    }

    cout << ans << endl;
  }
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
