#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;

  if (n % x != 0) {
    cout << -1 << "\n";
    return;
  }

  cout << x << " ";

  lin(i, 2, n) {
    if (i == x) {
      bool flag = false;
      for (int j = 2 * x; j <= n; j += x) {
        if (n % j == 0) {
          cout << j << " ";
          x = j;
          flag = true;

          break;
        }
      }

      if (flag)
        continue;
    }
    cout << i << " ";
  }

  cout << 1 << "\n";
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
