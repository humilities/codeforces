#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int r = n - 1;
  while (r) {
    if (s.substr(0, r) == s.substr(n - r))
      break;

    r--;
  }

  // cout << r << endl;

  string ans = s;
  for (int i = 0; i < k - 1; i++) {
    ans.insert(ans.end(), s.begin() + r, s.end());
  }

  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
