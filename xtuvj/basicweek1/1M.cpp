#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> a;

void dfs(ll cur, int c4, int c7) {
  if (cur > 777777444444LL)
    return;

  if (c4 == c7 && c4 > 0)
    a.push_back(cur);

  dfs(cur * 10 + 4, c4 + 1, c7);
  dfs(cur * 10 + 7, c4, c7 + 1);
}

void solve() {
  int n;
  cin >> n;

  sort(a.begin(), a.end());

  auto it = lower_bound(a.begin(), a.end(), n);
  if (it != a.end())
    cout << *it << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  dfs(0, 0, 0);
  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
