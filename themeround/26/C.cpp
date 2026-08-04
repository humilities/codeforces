#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int idx = n;
  if (!(n & 1)) {
    vector<int> v[2] = {vector<int>(26), vector<int>(26)};

    for (int i = 0; i < n; i++)
      v[i % 2][s[i] - 'a']++;
    for (int i = 0; i < 2; i++) {
      int mx = 0;

      for (int j = 0; j < 26; j++)
        mx = max(mx, v[i][j]);
      idx -= mx;
    }

    cout << idx << "\n";
  } else {
    vector<int> suf[2] = {vector<int>(26), vector<int>(26)};
    vector<int> pre[2] = {vector<int>(26), vector<int>(26)};

    for (int i = n - 1; i >= 0; i--)
      suf[i % 2][s[i] - 'a']++;
    for (int i = 0; i < n; i++) {
      suf[i % 2][s[i] - 'a']--;
      int ans = n;

      for (int j = 0; j < 2; j++) {
        int mx = 0;
        for (int k = 0; k < 26; k++)
          mx = max(mx, pre[j][k] + suf[1 - j][k]);

        ans -= mx;
      }
      idx = min(idx, ans);
      pre[i % 2][s[i] - 'a']++;
    }

    cout << idx << "\n";
  }
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
