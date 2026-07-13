#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn = 100005;
ll dp[mn];

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  map<int, int> cnt;
  int mv = 0;
  lin(i, 0, n) {
    cnt[a[i]]++;
    mv = max(mv, a[i]);
  }

  dp[0] = 0;
  dp[1] = cnt[1];

  lin(i, 2, mv + 1) dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * cnt[i]);

  cout << dp[mv] << "\n";
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
