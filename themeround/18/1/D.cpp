#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll l, r;
  cin >> l >> r;

  int k = 60;
  while (k) {
    if (((l >> k) & 1) != ((r >> k) & 1))
      break;
    k--;
  }

  ll x = (r >> k) << k;
  ll y = x - 1;

  ll z = 0;
  if (x + 1 <= r)
    z = x + 1;
  else
    z = y - 1;

  cout << x << " " << y << " " << z << "\n";
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
