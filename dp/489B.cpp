#include <bits/stdc++.h>

using namespace std;

int dp[105][105];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  cin >> m;
  vector<int> b(m + 1);
  for (int i = 1; i <= m; i++)
    cin >> b[i];

  sort(a.begin() + 1, a.end());
  sort(b.begin() + 1, b.end());

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

      if (abs(a[i] - b[j]) <= 1)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
