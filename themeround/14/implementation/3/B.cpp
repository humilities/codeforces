#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  sort(a.begin(), a.end());
  if (k == 0) {
    if (a[0] - 1)
      cout << 1 << "\n";
    else
      cout << -1 << "\n";
    return;
  } else if (k == n) {
    cout << a[n - 1] << "\n";
    return;
  } else {
    if (a[k - 1] != a[k])
      cout << a[k - 1] << "\n";
    else
      cout << -1 << "\n";
  }
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
