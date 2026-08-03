#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, x;
  cin >> n >> x;

  if (x == 1) {
    if (n & 1)
      cout << n << "\n";
    else
      cout << n + 3 << "\n";

    return;
  } else if (x == 0) {
    if (n == 1)
      cout << -1 << "\n";
    else if (n & 1)
      cout << n + 3 << "\n";
    else
      cout << n << "\n";

    return;
  } else {
    int c = __builtin_popcountll(x);

    if (n <= c)
      cout << x << "\n";
    else if (!((n - c) & 1))
      cout << (x + n - c) << "\n";
    else
      cout << (x + n - c + 1) << "\n";

    return;
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
