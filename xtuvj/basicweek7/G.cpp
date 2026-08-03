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

  lin(i, 0, n) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    cout << *it - a[i] << " \n"[i == n - 1];
  }

  vector<int> pos(n);
  int idx = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    pos[i] = idx;

    if (i && a[i] > b[i - 1])
      idx = i - 1;
  }

  lin(i, 0, n) cout << b[pos[i]] - a[i] << " \n"[i == n - 1];
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
