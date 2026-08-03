#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int tot = 2 * n;
  map<ll, int> fre;
  for (int i = 0; i < tot; i++) {
    ll val;
    cin >> val;
    fre[val]++;
  }

  int x = 0, y = 0, z = 0;
  for (auto const &[val, cnt] : fre) {
    if (cnt % 2 == 1) {
      x++;
    } else if (cnt % 4 == 2) {
      y++;
    } else if (cnt % 4 == 0) {
      z++;
    }
  }

  if (x > 0 || z % 2 == 0) {
    cout << x + 2 * y + 2 * z << endl;
  } else {
    cout << x + 2 * y + 2 * z - 2 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
