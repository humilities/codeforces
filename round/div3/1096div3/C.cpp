#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  vector<int> di6, di2, di3, di4;
  lin(i, 0, n) {
    if (a[i] % 6 == 0)
      di6.push_back(a[i]);
    else if (a[i] % 2 == 0)
      di2.push_back(a[i]);
    else if (a[i] % 3 == 0)
      di3.push_back(a[i]);
    else
      di4.push_back(a[i]);
  }

  vector<int> ans;
  for (auto i : di6)
    ans.push_back(i);
  for (auto i : di2)
    ans.push_back(i);
  for (auto i : di4)
    ans.push_back(i);
  for (auto i : di3)
    ans.push_back(i);

  lin(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
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
