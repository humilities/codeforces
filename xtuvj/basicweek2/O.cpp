#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> nee(31, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 30; j++)
      if ((a[i] >> j) & 1)
        nee[j]++;
  }

  ll ans = 0;
  for (int i = 30; i >= 0; i--) {
    int cnt = n - nee[i];

    if (k >= cnt) {
      k -= cnt;
      ans |= (1 << i);
    }
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
