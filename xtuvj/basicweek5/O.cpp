#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  sort(a.begin(), a.end());
  ll ans = 0;

  ans += a[n - 1];

  vector<ll> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
    suf[i] = suf[i + 1] + a[i];

  lin(i, 0, n - 1) {
    ll cnt = (n - 1) - i;
    ans += cnt * a[i] - suf[i + 1];
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
