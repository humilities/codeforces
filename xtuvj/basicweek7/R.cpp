#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  int ans = 0;

  int sm = 0;
  int len = 0;
  lin(i, 0, n) {
    int d = s[i] - '0';
    sm = (sm + d) % 3;
    len++;

    if (d % 3 == 0 || len == 3 || sm == 0) {
      ans++;

      sm = 0;
      len = 0;
    }
  }

  cout << ans;
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
