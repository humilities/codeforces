#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int n, m;
vector<int> a;
vector<vector<int>> gra;
int cnt = 0;

void dfs(int u, int p, int now) {
  if (a[u])
    now++;
  else
    now = 0;

  if (now > m)
    return;

  bool flag = true;
  for (auto v : gra[u]) {
    if (v != p) {
      flag = false;
      dfs(v, u, now);
    }
  }

  if (flag && u != 1)
    cnt++;
}

void solve() {
  cin >> n >> m;

  a.resize(n + 1);
  lin(i, 1, n + 1) cin >> a[i];

  gra.resize(n + 1);
  lin(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;

    gra[v].push_back(u);
    gra[u].push_back(v);
  }

  dfs(1, 0, 0);

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
