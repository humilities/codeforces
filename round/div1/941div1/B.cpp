#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int p = 0;
  while (1 << (p + 1) <= k) {
    p++;
  }

  vector<int> ans;

  for (int i = 0; i < 22; i++) {
    if (i != p) {
      ans.push_back(1 << i);
    }
  }

  ans.push_back(k - pow(2, p));
  ans.push_back(k + 1);
  ans.push_back(pow(2, p) + k + 1);

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
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
