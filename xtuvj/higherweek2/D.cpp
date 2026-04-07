#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int cnt[1000005];
int dp[2][3][3];

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i], cnt[a[i]]++;

  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;

  lin(i, 1, m + 1) {
    int cur = i % 2;
    int pre = (i - 1) % 2;

    memset(dp[cur], -1, sizeof(dp[cur]));

    lin(j, 0, 3) {
      lin(k, 0, 3) {
        if (dp[pre][j][k] == -1)
          continue;

        lin(l, 0, 3) {
          if (cnt[i] >= j + k + l) {
            int rem = cnt[i] - j - k - l;
            int ne = dp[pre][j][k] + l + (rem / 3);

            dp[cur][j][k] = max(dp[cur][j][k], ne);
          }
        }
      }
    }
  }

  cout << dp[m % 2][0][0] << "\n";
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
