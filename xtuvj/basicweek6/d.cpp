#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int m, s, t;
  cin >> m >> s >> t;

  vector<int> dp(t + 1, 0);
  lin(i, 1, t + 1) {
    if (m >= 10)
      dp[i] = dp[i - 1] + 60, m -= 10;
    else
      dp[i] = dp[i - 1], m += 4;
  }

  lin(i, 1, t + 1) {
    dp[i] = max(dp[i], dp[i - 1] + 17);

    if (dp[i] >= s) {
      cout << "Yes" << "\n";
      cout << i;

      return;
    }
  }

  cout << "No" << "\n";
  cout << dp[t];
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
