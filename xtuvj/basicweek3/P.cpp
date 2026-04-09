#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> c(n);
  vector<int> b(n);

  lin(i, 0, n) cin >> c[i];
  lin(i, 0, n) cin >> b[i];

  ll ans = 2e12;
  lin(i, 1, n - 1) {
    ll mi1 = 2e12;
    ll mi2 = 2e12;

    lin(j, 0, i) if (c[j] < c[i]) mi1 = min(mi1, (ll)b[j]);
    lin(j, i + 1, n) if (c[i] < c[j]) mi2 = min(mi2, (ll)b[j]);

    ans = min(ans, (ll)mi1 + mi2 + b[i]);
  }

  if (ans == 2e12) {
    cout << -1 << "\n";
    return;
  }

  cout << ans << "\n";
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
