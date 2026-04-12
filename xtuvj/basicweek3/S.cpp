#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  set<int> s;
  vector<int> a(n);
  lin(i, 0, n) cin >> a[i], s.insert(a[i]);

  if (s.size() > k) {
    cout << -1 << "\n";
    return;
  }

  vector<int> ans;
  for (auto val : s)
    ans.push_back(val);

  while (ans.size() < k)
    ans.push_back(1);

  cout << n * k << "\n";
  lin(i, 0, n) lin(j, 0, k) cout << ans[j] << " ";

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
