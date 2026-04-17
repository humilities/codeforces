#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  // cout << 1 << "\n";

  a.erase(unique(a.begin(), a.end()), a.end());

  int ans = 0;
  if (a.size() == 1) {
    cout << 1 << "\n";
    return;
  }

  lin(i, 1, a.size() - 1) if ((a[i] > a[i - 1] && a[i] > a[i + 1]) ||
                              (a[i] < a[i - 1] && a[i] < a[i + 1])) ans++;

  cout << ans + 2 << "\n";
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
