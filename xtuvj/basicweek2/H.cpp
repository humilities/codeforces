#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> ji;
  for (int i = 1; i <= n; i++)
    if (a[i] < i)
      ji.push_back(i);

  ll ans = 0;
  for (int val : ji) {
    auto it = lower_bound(ji.begin(), ji.end(), a[val]);
    ans += distance(ji.begin(), it);
  }

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
