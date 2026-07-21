#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++)
    cin >> b[i];

  vector<int> ans(n);

  ans[0] = b[0];
  ans[n - 1] = b[n - 2];

  for (int i = 1; i < n - 1; i++)
    ans[i] = b[i - 1] | b[i];

  bool ok = true;
  for (int i = 0; i < n - 1; i++) {
    if ((ans[i] & ans[i + 1]) != b[i]) {
      ok = false;
      break;
    }
  }

  if (!ok)
    cout << -1 << "\n";
  else
    for (int i = 0; i < n; i++)
      cout << ans[i] << " \n"[i == n - 1];
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
