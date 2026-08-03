#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> d;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1])
      d.push_back(i);
  }

  if (d.empty() || d.size() == 1) {
    cout << "YES" << "\n";
    return;
  }

  int km = 0;
  for (int d : d) {
    km = max(km, a[d] - a[d + 1]);
  }

  for (int j = 0; j < d.size() - 1; j++) {
    int l = d[j] + 1;
    int r = d[j + 1] - 1;

    if (l > r) {
      cout << "NO" << "\n";
      return;
    }

    int dif = -1;
    for (int t = l; t <= r; t++) {
      dif = max(dif, a[t + 1] - a[t]);
    }

    if (dif < km) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
