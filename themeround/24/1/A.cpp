#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll a, b;
  cin >> a >> b;

  if (a % 2 != 0 && b % 2 != 0)
    cout << a * b + 1 << "\n";

  else if (b % 2 == 0 && (a % 2 == 0 || (b / 2) % 2 == 0))
    cout << (a * b) / 2 + 2 << "\n";

  else
    cout << -1 << "\n";
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
