#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

struct edge {
  int to, id;
};

void solve() {
  int n;
  cin >> n;

  vector<vector<edge>> adj(n + 1);
  vector<int> du(n + 1);
  lin(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, i});
    adj[v].push_back({u, i});

    du[v]++;
    du[u]++;
  }

  bool flag = false;
  int sta = 0;
  lin(i, 1, n + 1) {
    if (du[i] >= 3) {
      flag = true;
      break;
    }

    if (du[i] == 1)
      sta = i;
  }

  if (flag) {
    cout << -1 << "\n";
    return;
  }

  vector<int> ans(n - 1);
  int we = 2;
  int pre = -1;
  int cur = sta;

  lin(i, 0, n - 1) {
    for (auto &edge : adj[cur]) {
      if (edge.to != pre) {
        ans[edge.id] = we;
        we = (we == 2) ? 3 : 2;

        pre = cur;
        cur = edge.to;

        break;
      }
    }
  }

  lin(i, 0, n - 1) cout << ans[i] << " \n"[i == n - 2];
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
