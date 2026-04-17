#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  ll ans = 1;
  ll can = 1;
  while (can < n) {
    ans++;
    can = can * 2 + 2;
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
