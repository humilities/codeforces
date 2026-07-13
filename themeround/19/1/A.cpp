#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;
  vector<int> odd;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1)
      odd.push_back(a[i]);
    else
      ans += a[i];
  }

  sort(odd.begin(), odd.end(), greater<>());
  int num = (odd.size() + 2 - 1) / 2;

  if (num == 0) {
    cout << 0 << "\n";
    return;
  }

  for (int i = 0; i < num; i++)
    ans += odd[i];
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
