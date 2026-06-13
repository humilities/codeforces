#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int mn = 0, mi = 1e9;
  for (int i = 0; i < n; i++) {
    mn = max(mn, a[i]);
    mi = min(mi, a[i]);
  }

  cout << mn - mi + 1 << "\n";
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
