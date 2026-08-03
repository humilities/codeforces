#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int c1 = 0, c0 = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] == 0)
      c0++;
    if (a[i] == -1)
      c1++;
  }

  int ans = 0;
  if (c1 % 2 == 1)
    ans += 2;

  cout << ans + c0 << endl;
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
