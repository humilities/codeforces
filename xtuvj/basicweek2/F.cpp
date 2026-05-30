#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  ll sum = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum <= k) {
    cout << n << "\n";
    return;
  }

  ll l = (k + 1) / 2;
  ll r = k / 2;

  int le = 0, ri = n - 1;
  while (le <= r && l >= a[le]) {
    l -= a[le];
    le++;
  }

  // cout << le << endl;

  while (ri >= le && r >= a[ri]) {
    r -= a[ri];
    ri--;
  }

  // cout << le << " " << ri << "\n";

  cout << n - (ri - le + 1) << "\n";
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
