#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  ll m;
  cin >> n >> m;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> suf(n + 2, 2e9);
  for (int i = n; i >= 1; i--)
    suf[i] = min(suf[i + 1], a[i]);

  vector<int> ans;
  int cnt = 0;
  for (int i = n; i >= 1; i--) {
    if (m >= i && cnt + 1 <= suf[i]) {
      m -= i;
      cnt++;
      ans.push_back(i);
    }
  }

  if (m != 0)
    cout << -1 << "\n";
  else {
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " \n"[i == ans.size() - 1];
  }
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
