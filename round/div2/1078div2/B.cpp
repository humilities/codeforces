#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  int n, x, y;
  ll ti = 0;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ti += a[i] / x;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll cur = ti - a[i] / x;
    ll val = a[i] + 1LL * cur * y;

    if (val > ans)
      ans = val;
  }

  cout << ans << endl;
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
