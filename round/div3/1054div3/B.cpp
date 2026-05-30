#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  int ans = -1e9;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  for (int i = 0; i < n - 1; i += 2) {
    ans = max(ans, abs(a[i] - a[i + 1]));
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
