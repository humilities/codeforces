#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int m1 = max(a, b);
  int n1 = min(a, b);

  int rem = ceil((double)m1 / (n1 + 1));
  if (rem >= 3) {
    cout << "NO" << "\n";
    return;
  } else {
    c = c - a;
    d = d - b;

    // cout << c << " " << d << "\n";

    m1 = max(c, d);
    n1 = min(c, d);

    rem = ceil((double)m1 / (n1 + 1));

    // cout << rem << "\n";

    if (rem >= 3) {
      cout << "NO" << "\n";
      return;
    }

    cout << "YES" << "\n";
  }
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
