#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> col(n + 1, 0);
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) {
      int c1 = 0;
      int c2 = 0;
      bool flag = false;

      queue<int> q;
      q.push(i);
      col[i] = 1;
      c1++;

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
          if (col[v] == 0) {
            col[v] = 3 - col[u];
            if (col[v] == 1)
              c1++;
            else
              c2++;

            q.push(v);
          } else {
            if (col[v] == col[u])
              flag = true;
            ;
          }
        }
      }

      if (!flag)
        ans += max(c1, c2);
    }
  }

  cout << ans << "\n";
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
