#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mn = 200005;

vector<bool> vis(mn);
vector<int> adj[mn];
int entry = -1;
vector<int> path;

bool dfs1(int u, int p) {
  vis[u] = true;

  for (auto v : adj[u]) {
    if (v != p && vis[v]) {
      entry = v;
      return true;
    } else if (v != p && !vis[v])
      if (dfs1(v, u))
        return true;
  }

  return false;
}

int dfs2(int u) {
  vis[u] = true;
  int ans = mn;

  for (auto v : adj[u]) {
    if (v == entry)
      return 1;
    if (!vis[v]) {
      int cur = dfs2(v) + 1;
      ans = min(ans, cur);
    }
  }

  return ans;
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs1(b, -1);
  vis.assign(n + 1, false);
  int dism = n, disa = 0;

  if (entry == a)
    dism = 0;
  else
    dism = dfs2(a);

  vis.assign(n + 1, false);
  if (entry == b)
    disa = 0;
  else
    disa = dfs2(b);

  if (disa < dism)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    vis[i] = false;
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
