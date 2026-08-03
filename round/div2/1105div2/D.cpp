#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 998244353;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum ^= a[i];
  }

  if (n == 1) {
    cout << 0 << "\n";
    return;
  }

  ll ans = 0;
  if (sum == 0)
    ans++;

  for (int i = 0; i < n; i++)
    if ((sum ^ a[i]) < a[i])
      ans++;

  cout << ans % mod << "\n";
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
