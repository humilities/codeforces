#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  map<int, int> ma;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    if (val <= n)
      ma[val]++;
  }

  vector<int> ans(n + 1, 0);
  for (auto &[ju, cnt] : ma) {
    for (int i = ju; i <= n; i += ju)
      ans[i] += cnt;
  }

  int as = 0;
  for (int i = 1; i <= n; i++)
    as = max(as, ans[i]);

  cout << as << endl;
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
