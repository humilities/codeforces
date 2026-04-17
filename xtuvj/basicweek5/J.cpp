#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  ll sum = 0;
  ll ma = 0;
  lin(i, 0, n) {
    ma = max(ma, (ll)a[i]);
    sum += a[i];
  }

  ll tar = (sum + n - 2) / (n - 1);
  ll x = max(tar, ma);

  cout << x * (n - 1) - sum << "\n";
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
