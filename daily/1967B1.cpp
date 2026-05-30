#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += (n + i) / (1LL * i * i);
  }

  cout << ans - 1 << endl;
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
