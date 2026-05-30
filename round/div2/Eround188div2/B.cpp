#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int cnt = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
    cin >> ans[i];

  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] >= cur)
      cnt++, cur = ans[i];
  }

  cout << cnt << endl;
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
