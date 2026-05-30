#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  int cnt = -2e9;
  for (int i = 1; i <= n; i++)
    if ((a[i] - b[i]) > cnt)
      cnt = a[i] - b[i];

  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (a[i] - b[i] == cnt)
      ans.push_back(i);

  cout << ans.size() << "\n";
  for (int val : ans)
    cout << val << " ";

  cout << "\n";
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
