#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int a, b;
  cin >> a >> b;

  string s;
  cin >> s;

  string ans = "";
  int rem = 0;

  for (int i = 0; i < b; i++) {
    bool flag = false;
    int sta = (i == 0) ? 1 : 0;

    for (int j = sta; j <= 9; j++) {
      int cur = (rem * 10 + j) % a;

      if (s[i] == '1') {
        if (cur == 0) {
          ans += '0' + j;
          rem = cur;
          flag = true;
          break;
        }
      } else {
        if (cur != 0) {
          ans += '0' + j;
          rem = cur;
          flag = true;
          break;
        }
      }
    }

    if (!flag) {
      cout << -1 << endl;
      return;
    }
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
