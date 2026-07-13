#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  vector<int> ma(k + 2);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++) {
    if ((a[i] > 0 || a[i] == 0) && (a[i] < k || a[i] == k))
      ma[a[i]]++;
  }

  int ans = 0;
  for (int i = 0; i < k; i++) {
    if (ma[i] == 0)
      ans++;
  }

  ma[k] = ((ma[k] - ans > 0) ? (ma[k] - ans) : 0);
  ans += ma[k];

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
