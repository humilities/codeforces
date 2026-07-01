#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<bool> vis(n + 1, false);
  vector<int> ans;

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    else {
      int num = i;
      int cnt = 2;
      ans.push_back(num);

      // cout << "num==" << num << " ";

      while (num < n) {
        num *= cnt;

        if (num <= n)
          ans.push_back(num);
        else
          break;

        // cout << num << " ";

        vis[num] = true;
      }

      // cout << "\n";
    }
  }

  // cout << "output" << " ";

  for (auto val : ans)
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
