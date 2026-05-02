#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<bool> cur(2, false);
  cur[0] = true;

  for (int i = 1; i <= n; i++) {
    vector<bool> nex(2, false);
    bool flag = false;

    for (int j = 0; j < 2; j++) {
      if (!cur[j])
        continue;

      char ch1 = ((j + 1) % 2 == 1) ? 'a' : 'b';
      char ch2 = ((n - i + 1 + j) % 2 == 1) ? 'a' : 'b';

      if (s[i - 1] == '?' || s[i - 1] == ch1) {
        nex[(j + 1) % 2] = true;
        flag = true;
      }
      if (s[i - 1] == '?' || s[i - 1] == ch2) {
        nex[j] = true;
        flag = true;
      }
    }

    if (!flag) {
      cout << "NO" << "\n";
      return;
    }

    cur = nex;
  }

  cout << "YES" << "\n";
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
