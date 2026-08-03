#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> p(n);
  lin(i, 0, n) cin >> p[i];

  int ans = 0;
  int mn = 1e8;
  int mnl = 1e8;

  lin(i, 0, n) {
    bool suc = (mn < p[i]);
    bool los = (mnl < p[i]);

    bool lose;
    if (!suc)
      lose = false;
    else if (!los) {
      lose = true;
      ans++;
    } else
      lose = false;

    mn = min(mn, p[i]);
    if (lose)
      mnl = min(mnl, p[i]);
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
