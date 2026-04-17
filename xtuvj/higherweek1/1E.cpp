#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> pu(n + 1);
  vector<int> pa(m);

  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> pu[i];

  for (int i = 0; i < m; i++) {
    int pos;
    cin >> pos;

    vis[pos] = 1;
    pa[i] = pu[pos];
  }

  // cout << 1 << endl;
  sort(pa.begin(), pa.end(), greater<int>());

  ll base = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i] == 0)
      base += pu[i];

  for (int i = 0; i < m; i++) {
    if (base > pa[i])
      base *= 2;
    else
      base += pa[i];
  }

  cout << base << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
