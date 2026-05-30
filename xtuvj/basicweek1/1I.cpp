#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < cnt)
      ans++;
    else
      cnt += a[i];
    // cout << cnt << " " << ans << "\n";
  }

  // cout << endl;

  cout << n - ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
