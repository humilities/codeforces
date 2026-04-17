#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  int n, m, k;
  ll ans = 0;
  int fe = 0;
  cin >> n >> m >> k;

  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  sort(b.begin(), b.end());
  for (int i = 1; i <= n; i++) {
    int p = min(m, k);
    ans += 1LL * p * (b[i] + fe);

    fe += p;
    k -= p;
  }

  cout << ans << endl;
  // for (auto const &[key, val] : a)
  // cout << key << " " << val << endl;
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
