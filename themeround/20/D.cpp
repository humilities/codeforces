#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  ll base = 1;
  while (true) {
    ll cnt = (n + 1) / 2;
    if (k <= cnt) {
      cout << base * (2 * k - 1) << "\n";
      return;
    }

    k -= cnt;
    n /= 2;
    base *= 2;
  }
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
