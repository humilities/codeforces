#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> ans(n + 1);
  int cnt = 0;

  for (int i = n; i >= 0; i--)
    ans[cnt++] = i;

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
