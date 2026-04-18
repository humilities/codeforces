#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

bool check(int sta, int len, vector<int> &a) {
  set<int> res;

  int ma = 0;
  lin(i, sta, sta + len) {
    res.insert(a[i]);
    ma = max(ma, a[i]);
  }

  if (ma == len && res.size() == len)
    return true;
  else
    return false;
}

void solve() {
  int n;
  cin >> n;

  int ma = 0;
  vector<int> a(n);
  lin(i, 0, n) cin >> a[i], ma = max(ma, a[i]);

  set<pair<int, int>> ans;
  int l1 = ma, l2 = n - ma;
  if (l2 > 0)
    if (check(0, ma, a) && check(l1, l2, a))
      ans.insert({l1, l2});

  l1 = n - ma, l2 = ma;
  if (l1 > 0)
    if (check(0, l1, a) && check(l1, l2, a))
      ans.insert({l1, l2});

  cout << ans.size() << "\n";
  for (auto [l1, l2] : ans)
    cout << l1 << " " << l2 << "\n";
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
