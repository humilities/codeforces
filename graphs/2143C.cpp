#include <bits/stdc++.h>

using namespace std;

struct edge {
  int u, v, x, y;
};

void solve() {
  int n;
  cin >> n;

  vector<int> de(n, 0);
  vector<vector<int>> gq(n);
  vector<vector<int>> gh(n);

  vector<edge> e(n - 1);

  for (auto &[u, v, x, y] : e) {
    cin >> u >> v >> x >> y;
    u--, v--;

    if (x > y) {
      gq[u].push_back(v);
      gh[v].push_back(u);
      de[u]++;
    } else {
      gq[v].push_back(u);
      gh[u].push_back(v);
      de[v]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (de[i] == 0)
      q.push(i);

  vector<int> ans(n);
  for (int i = 1; i <= n; i++) {
    int f = q.front();
    ans[f] = i;
    q.pop();

    for (const auto &v : gh[f]) {
      de[v]--;

      if (de[v] == 0)
        q.push(v);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
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
