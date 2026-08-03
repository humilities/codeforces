/*P1303*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  int len1 = s.length();
  int len2 = t.length();
  vector<int> a(len1 + 1);
  vector<int> b(len2 + 1);

  for (int i = 1; i <= len1; i++)
    a[i] = s[len1 - i] - '0';
  for (int i = 1; i <= len2; i++)
    b[i] = t[len2 - i] - '0';

  vector<int> c(len1 + len2 + 2);
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++)
      c[i + j - 1] += a[i] * b[j];
  }

  for (int i = 1; i < len1 + len2 + 1; i++) {
    if (c[i] > 9) {
      c[i + 1] += c[i] / 10;
      c[i] = c[i] % 10;
      ;
    }
  }

  int len = len1 + len2;
  while (c[len] == 0 && len > 1)
    len--;

  for (int i = len; i >= 1; i--)
    cout << c[i];
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
