#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  int num;

  cin >> num;
  cin >> n >> m;

  int ans = (n / 2 + m) > num ? num : (n / 2 + m);
  cout << ans << endl;
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
