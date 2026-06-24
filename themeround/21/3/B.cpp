#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  vector<int> ma(26);
  for (char ch : s)
    ma[ch - 'a']++;

  bool flag = true;
  vector<int> mo(26);
  for (auto ch : t)
    mo[ch - 'a']++;

  for (int i = 0; i < 26; i++) {
    if (ma[i] > mo[i]) {
      flag = false;
      break;
    }
  }

  if (!flag) {
    cout << "Impossible" << "\n";
    return;
  }

  string ans = "";
  int slen = s.length();
  int tlen = t.length();
  int idx = 0;

  vector<vector<int>> suf(slen + 1, vector<int>(26, 0));
  for (int i = slen - 1; i >= 0; i--) {
    for (int c = 0; c < 26; c++)
      suf[i][c] = suf[i + 1][c];
    suf[i][s[i] - 'a']++;
  }

  for (int i = 0; i < tlen; i++) {
    for (int j = 0; j < 26; j++) {
      if (mo[j] > 0) {
        mo[j]--;

        int nex = idx;
        if (idx < slen && s[idx] - 'a' == j)
          nex++;

        bool is = true;
        for (int k = 0; k < 26; k++) {
          if (mo[k] < suf[nex][k]) {
            is = false;
            break;
          }
        }

        if (is) {
          ans += ('a' + j);
          idx = nex;
          break;
        }

        mo[j]++;
      }
    }
  }

  cout << ans << "\n";
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
