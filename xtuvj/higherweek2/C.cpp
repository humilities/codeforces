#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int mv = 1000005;
vector<int> yu[mv];
int dp[mv];

void pre() {
  for (int i = 1; i < mv; i++)
    for (int j = i; j < mv; j += i)
      yu[j].push_back(i);

  for (int i = 1; i < mv; i++)
    reverse(yu[i].begin(), yu[i].end());
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  dp[0] = 1;

  for (int i = 0; i < n; i++)
    for (int val : yu[a[i]])
      dp[val] = (dp[val] + dp[val - 1]) % mod;

  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + dp[i]) % mod;

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
