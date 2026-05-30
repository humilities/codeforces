#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;

  ll cur = 0;
  ll ans = 0;
  ll mn = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+')
      cur++;
    else
      cur--;

    if (cur < mn)
      mn = cur, ans += (i + 1);
  }

  ans += s.length();
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
