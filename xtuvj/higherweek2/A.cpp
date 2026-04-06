#include <bits/stdc++.h>

using namespace std;

int dp[26][26];

void solve() {
  int n;
  cin >> n;

  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++) {
    string s = a[i];
    int len = s.length();
    int l = s[0] - 'a';
    int r = s[len - 1] - 'a';

    for (int j = 0; j < 26; j++)
      if (dp[j][l])
        dp[j][r] = max(dp[j][l] + len, dp[j][r]);

    dp[l][r] = max(dp[l][r], len);
  }

  int ma = 0;
  for (int i = 0; i < 26; i++)
    ma = max(ma, dp[i][i]);

  cout << ma << "\n";
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
