#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  int c1 = 1;
  int c2 = 0;

  int flag = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0)
      flag *= -1;

    if (flag > 0)
      c1++;
    else
      c2++;
  }

  cout << 1LL * c1 * c2 << " "
       << 1LL * c1 * (c1 - 1) / 2 + 1LL * c2 * (c2 - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
