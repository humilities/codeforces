#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> ans;

  int l = 1, r = k + 1;
  for (int i = 1; i <= k + 1; i++) {
    if (i % 2 == 1)
      ans.push_back(l), l++;
    else
      ans.push_back(r), r--;
  }

  for (int i = k + 2; i <= n; i++)
    ans.push_back(i);

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
