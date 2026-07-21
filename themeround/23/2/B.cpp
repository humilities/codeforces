#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  ll sum = 0;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  vector<ll> pre(n + 1, 0);
  for (int i = 0; i < n; i++)
    pre[i + 1] = pre[i] + a[i];

  ll mn = 0;
  ll mi = 0;
  for (int r = 1; r <= n; r++) {
    ll i = (ll)r * r + r - pre[r];
    mn = max(mn, i - mi);
    mi = min(mi, i);
  }

  cout << sum + mn << "\n";
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
