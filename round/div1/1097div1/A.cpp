#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is(const string &s) {
  int cnt = 0;

  for (auto ch : s) {
    if (ch == '(')
      cnt++;
    else
      cnt--;

    if (cnt < 0)
      return false;
  }

  return cnt == 0;
}

void solve() {
  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  string c = a, d = b;
  int cnt = 1;

  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (cnt & 1) {
        c[i] = '(';
        d[i] = ')';

        cnt++;
      } else {
        c[i] = ')';
        d[i] = '(';

        cnt++;
      }
    }
  }

  if (is(c) && is(d))
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
