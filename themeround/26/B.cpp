#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  ll ma = -1e18;
  bool has = false;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
    if (a[i] > 0) {
      has = true;
    }
  }

  if (!has) {
    cout << ma << "\n";
    return;
  }

  ll n1 = 0, n2 = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      n1 += max(0LL, a[i]);
    else
      n2 += max(0LL, a[i]);
  }

  cout << max(n1, n2) << "\n";
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
