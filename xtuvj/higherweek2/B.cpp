#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[100005];
map<int, int> ma;

void solve() {
  int n;
  cin >> n;

  int mn = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], ma[a[i]]++, mn = max(mn, a[i]);

  dp[0] = 0;
  dp[1] = 1 * ma[1];

  for (int i = 2; i <= mn; i++)
    dp[i] = max(dp[i - 1], dp[i - 2] + (ll)i * ma[i]);

  cout << dp[mn] << "\n";
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
