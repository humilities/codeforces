#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[510][510];
int a[510];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, b, mod;
  cin >> n >> m >> b >> mod;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = a[i]; k <= b; k++) {
        dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
      }

  ll cnt = 0;

  for (int i = 0; i <= b; i++) {
    cnt = (cnt + dp[m][i]) % mod;
  }

  cout << cnt << endl;

  return 0;
}
