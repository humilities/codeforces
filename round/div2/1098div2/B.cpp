#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;

  if (n <= 3) {
    cout << 1 << "\n";
    return;
  }

  int c1 = abs(a - b);
  int c2 = n - c1;

  cout << min(c2, c1) + k << "\n";
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
