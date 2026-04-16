#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  lin(i, 0, n) cin >> a[i];
  sort(a.begin(), a.end());

  ll mn = a[0];
  lin(i, 0, n - 1) mn = min(mn, a[i + 1] - a[i]);

  ll ans = mn;

  if (k >= 3) {
    cout << 0 << "\n";
  } else if (k == 1) {
    cout << mn << "\n";
  } else {
    lin(i, 0, n) {
      lin(j, i + 1, n) {
        ll d = a[j] - a[i];

        auto it = lower_bound(a.begin(), a.end(), d);
        ll n1 = 1e18;
        ll n2 = 1e18;

        if (it != a.end())
          n1 = abs(*(it)-d);
        if (it != a.begin())
          n2 = abs(d - *(it - 1));

        ans = min({ans, n1, n2});

        // cout << "ans=" << ans << " " << "d=" << d << "\n";
      }
    }

    cout << ans << "\n";
  }

  return;
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
