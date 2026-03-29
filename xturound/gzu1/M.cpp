#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  int cntj = 0, cnto = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] % 2 == 0)
      cnto++;
    else
      cntj++;
  }

  if (n == 1) {
    cout << "YES" << endl;
    return;
  }

  // cout << cntj << " " << cnto << endl;
  if (cntj >= (n - 2) / 3 + 1) {
    cout << "YES" << "\n";
  } else
    cout << "NO" << "\n";
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
