#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

struct edg {
  int to;
  int id;
};

const int mn = 200005;
int dp[mn];
int pos[mn];
vector<edg> adj[mn];

void dfs(int u, int p) {
  for (auto &ed : adj[u]) {
    int v = ed.to;
    int idx = ed.id;

    if (v == p)
      continue;

    if (idx < pos[u])
      dp[v] = dp[u] + 1;
    else
      dp[v] = dp[u];

    pos[v] = idx;

    dfs(v, u);
  }
}

void solve() {
  int n;
  cin >> n;

  lin(i, 1, n + 1) {
    adj[i].clear();
    dp[i] = 0;
    pos[i] = 0;
  }

  lin(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, i + 1});
    adj[v].push_back({u, i + 1});
  }

  dp[0] = 1;
  pos[0] = 0;

  dfs(1, 0);

  int ans = 0;
  lin(i, 1, n + 1) ans = max(ans, dp[i]);

  cout << ans + 1 << "\n";
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
