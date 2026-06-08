#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = a[0];
  int cur = a[0];

  for (int i = 1; i < n; i++) {
    if ((a[i] & 1) != (a[i - 1] & 1))
      cur += a[i];
    else
      cur = a[i];

    ans = max(ans, cur);
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
