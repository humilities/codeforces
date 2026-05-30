#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  if (n == 2) {
    int u, v;
    cin >> u >> v;
    cout << 0 << endl;
    return;
  }

  vector<vector<int>> a(n + 1);
  vector<int> de(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    a[u].push_back(v);
    a[v].push_back(u);
    de[u]++;
    de[v]++;
  }

  int toll = 0;
  vector<bool> leaf(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (de[i] == 1) {
      leaf[i] = true;
      toll++;
    }
  }

  vector<int> adle(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (const int ne : a[i]) {
      if (leaf[ne]) {
        adle[i]++;
      }
    }
  }

  int ans = n;
  for (int i = 1; i <= n; i++) {
    int cur = 0;

    if (leaf[i]) {
      cur = toll - 1 - adle[i];
    } else {
      cur = toll - adle[i];
    }

    ans = min(ans, cur);
  }

  cout << ans << endl;
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
