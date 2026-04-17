#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  ll mn = max((ll)a[0], (ll)abs(a[0]));
  ll mi = min((ll)a[0], (ll)abs(a[0]));

  lin(i, 1, n) {
    ll v1 = mn + a[i];
    ll v2 = abs(mn + a[i]);
    ll v3 = mi + a[i];
    ll v4 = abs(mi + a[i]);

    mn = max({v1, v2, v3, v4});
    mi = min({v1, v2, v3, v4});
  }

  cout << mn << "\n";
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
