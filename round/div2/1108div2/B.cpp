#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  if (n == 2) {
    cout << -1 << "\n";
    return;
  }

  vector<ll> ans;
  ans.push_back(1);
  ans.push_back(2);
  ans.push_back(3);

  ll cur = 6;
  for (int i = 4; i <= n; i++) {
    ans.push_back(cur);
    cur *= 2;
  }

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
