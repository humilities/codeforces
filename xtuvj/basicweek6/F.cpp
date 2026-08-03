#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn = 3000005;
vector<int> qu[mn];
ll dp[mn];

void solve() {
  int n;
  cin >> n;

  int idx = 0;
  lin(i, 0, n) {
    int x, y;
    cin >> x >> y;

    x++, y++;
    qu[y].push_back(x);

    if (y > idx)
      idx = y;
  }

  lin(i, 1, idx + 1) {
    dp[i] = dp[i - 1];

    for (auto x : qu[i])
      dp[i] = max(dp[i], dp[x - 1] + (i - x + 1));
  }

  cout << dp[idx] << "\n";
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
