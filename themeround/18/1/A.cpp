#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n - 2; i++) {
    if (a[i]) {
      a[i + 1] -= a[i] * 2;
      a[i + 2] -= a[i];
      a[i] = 0;

      if (a[i + 1] < 0 || a[i + 2] < 0) {
        cout << "NO" << "\n";
        return;
      }
    }
  }

  if (a[n - 1] == 0 && a[n - 2] == 0)
    cout << "YES" << "\n";
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
