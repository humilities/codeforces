// P1601
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  string c = "";
  int jw = 0;
  int len = max(s.length(), t.length());

  while (s.length() < len)
    s = '0' + s;
  while (t.length() < len)
    t = '0' + t;

  for (int i = len - 1; i >= 0; i--) {
    int t1 = s[i] - '0', t2 = t[i] - '0';
    int ti = t1 + t2 + jw;

    jw = ti / 10;
    char ch = ti % 10 + '0';

    c = ch + c;
  }
  if (jw)
    cout << '1' + c;
  else
    cout << c;
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
