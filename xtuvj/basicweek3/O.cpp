#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1);
  lin(i, 1, n + 1) cin >> v[i];

  ll ans = 0;
  lin(i, 0, m) {
    int x, y;
    cin >> x >> y;
    ans += min(v[x], v[y]);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
