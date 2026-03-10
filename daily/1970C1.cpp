#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  vector<vector<int>> a(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    a[u].push_back(v);
    a[v].push_back(u);
  }

  int be = 0;
  cin >> be;

  int lef = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i].size() == 1) {
      lef = i;
      break;
    }
  }

  vector<int> qu = {lef};
  vector<int> dis(n + 1, -1);

  dis[lef] = 0;

  int fir = 0;
  while (fir < qu.size()) {
    int cur = qu[fir++];

    for (int neb : a[cur]) {
      if (dis[neb] == -1) {
        dis[neb] = dis[cur] + 1;
        qu.push_back(neb);
      }
    }
  }

  int l = dis[be];
  int r = n - 1 - l;

  if (l % 2 != 0 || r % 2 != 0)
    cout << "Ron" << endl;
  else
    cout << "Hermione" << endl;

  return 0;
}
