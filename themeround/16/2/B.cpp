#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector<ll> ans(n + 1);
  ans[1] = 1;

  int x = 2;

  for (int i = 2; i <= n; i++) {
    ll las = i - (b[i] - b[i - 1]);

    if (las == 0)
      ans[i] = x++;
    else
      ans[i] = ans[las];
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
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
