#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
  int to;
  int id;
};

int n;

vector<vector<edge>> adj;
vector<pair<int, int>> ans;

void dfs(int u, int p, int type) {
  for (auto &edg : adj[u]) {
    int v = edg.to;
    int id = edg.id;
    if (v == p)
      continue;

    if (type == 1) {
      ans[id] = {u, v};
      dfs(v, u, 2);
    } else {
      ans[id] = {v, u};
      dfs(v, u, 1);
    }
  }
}

void solve() {
  cin >> n;

  adj.assign(n + 1, vector<edge>());
  vector<int> de(n + 1, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    de[u]++;
    de[v]++;
  }

  int sta = -1;
  for (int i = 1; i <= n; i++) {
    if (de[i] == 2) {
      sta = i;
      break;
    }
  }

  if (sta == -1) {
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
  ans.resize(n);

  int nr = adj[sta][0].to, i1 = adj[sta][0].id;
  int nl = adj[sta][1].to, i2 = adj[sta][1].id;
  ans[i1] = {nr, sta};
  ans[i2] = {sta, nl};

  dfs(nr, sta, 1);
  dfs(nl, sta, 2);

  for (int i = 1; i < n; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
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
