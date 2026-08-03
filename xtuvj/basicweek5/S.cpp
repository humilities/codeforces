#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  lin(i, 1, m + 1) for (int j = i; j <= n; j += i) if ((j / i + 1) % i == 0)
      ans++;

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
