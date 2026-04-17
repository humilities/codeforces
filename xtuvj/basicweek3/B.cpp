#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, d;
  cin >> n >> d;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (a[i] - a[j] > d)
      j++;

    int cnt = i - j;
    if (cnt >= 2)
      ans += (1LL) * cnt * (cnt - 1) / 2;
  }

  cout << ans << endl;
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
