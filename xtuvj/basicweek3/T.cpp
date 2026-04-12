#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);
  lin(i, 0, n) cin >> a[i];
  lin(i, 0, n) cin >> b[i];

  vector<int> pos1(n + 1);
  vector<int> pos2(n + 1);

  lin(i, 0, n) pos1[a[i]] = i;
  lin(i, 0, n) pos2[b[i]] = i;

  vector<int> dif(n);
  lin(i, 1, n + 1) dif[(pos1[i] - pos2[i] + n) % n]++;

  int ans = 0;
  lin(i, 0, n) ans = max(ans, dif[i]);

  cout << ans << "\n";
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
