#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;

  string a, b;
  cin >> a >> b;

  int cnt = 0;
  vector<int> pos;
  lin(i, 0, n) {
    if (a[i] != b[i]) {
      cnt++;

      pos.push_back(i);
    }
  }

  if (cnt & 1) {
    cout << -1 << "\n";
    return;
  }

  ll sum = 0;
  if (cnt == 2 && pos[0] == pos[1] - 1)
    sum = min(x, 2 * y);
  else
    sum = (ll)(cnt / 2) * y;

  cout << sum << "\n";
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
