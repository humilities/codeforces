#include <bits/stdc++.h>
#include <string>

using namespace std;
using ll = long long;

void solve() {
  int k, p;
  cin >> k >> p;

  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    string s = to_string(i);
    string rev = s;

    reverse(rev.begin(), rev.end());

    string num = s + rev;
    ans = (ans + stoll(num)) % p;
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
