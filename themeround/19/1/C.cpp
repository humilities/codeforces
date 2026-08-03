#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();

  for (int i = 0; i < n; i++) {
    int lim = min(i + 9, n - 1);
    int bes = i;
    int mn = s[i] - '0';

    for (int j = i + 1; j <= lim; j++) {
      int val = s[j] - '0' - (j - i);

      if (val > mn) {
        mn = val;
        bes = j;
      }
    }

    char tar = mn + '0';
    for (int j = bes; j > i; j--)
      s[j] = s[j - 1];

    s[i] = tar;
  }

  cout << s << "\n";
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
