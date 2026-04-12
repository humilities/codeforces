#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int m = d - b;
  int n = (d - c) - (b - a);

  if (m < 0 || n < 0) {
    cout << -1 << "\n";
    return;
  }

  cout << m + n << "\n";
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
