#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll sum = 0;
  int ma = 0;

  for (int i = 0; i < n; i++) {
    sum += a[i];
    ma = max(ma, a[i]);
  }

  sum = (sum + x - 1) / x;

  cout << max((ll)ma, sum) << "\n";
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
