#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  int cnt = 0;
  lin(i, 1, n + 1) {
    cin >> a[i];
    if (a[i] > 0)
      cnt++;
  }

  ll sum = 0;
  ll ans = 0;

  lin(i, 1, n + 1) sum += a[i];
  ans = sum - (n - 1);

  ans = min({(ll)n, (ll)cnt, ans});

  if (ans > n)
    cout << n << "\n";
  else
    cout << max((ll)1, ans) << "\n";
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
