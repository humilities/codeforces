#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int mn = 2e9;
  int pos = -1;

  for (int i = 1; i <= n; i++)
    if (a[i] < mn) {
      mn = a[i];
      pos = i;
    }

  cout << n - 1 << "\n";
  for (int i = 1; i <= n; i++) {
    if (i == pos)
      continue;

    cout << pos << " " << i << " " << mn << " " << mn + abs(i - pos) << "\n";
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
