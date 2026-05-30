#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> du(n + 5);
  vector<int> ma(n + 5);

  lin(i, 0, m) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);

    du[u]++;
    du[v]++;
  }

  lin(i, 1, n + 2) ma[du[i]]++;

  int y = ma[1];
  int x = 0;
  int pos = 0;

  lin(i, 2, n + 1) {
    if (ma[i] == 1)
      pos = i;
    else if (ma[i] == 0)
      continue;
    else {
      x = ma[i];
    }
  }

  if (pos == 0)
    x--;

  cout << x << " " << y / x << "\n";
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
