#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  string s;
  cin >> s;

  int cur = 0;
  int dis = 0;
  bool flag = true;

  while (cur <= n) {
    if (cur == 0 || s[cur - 1] == 'L') {
      int nex = -1;

      for (int i = min(n + 1, cur + m); i > cur; i--)
        if (i == (n + 1) || s[i - 1] == 'L') {
          nex = i;
          break;
        }

      if (nex == -1) {
        for (int i = min(n + 1, cur + m); i > cur; i--)
          if (i == (n + 1) || s[i - 1] == 'W') {
            nex = i;
            break;
          }
      }

      if (nex == -1) {
        flag = false;
        break;
      }

      cur = nex;
    } else if (s[cur - 1] == 'W') {
      cur++;
      dis++;

      if (dis > k) {
        flag = false;
        break;
      }

      if (cur <= n && s[cur - 1] == 'C') {
        flag = false;
        break;
      }
    }
  }

  if (flag)
    cout << "YES" << "\n";
  else
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
