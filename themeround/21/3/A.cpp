#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  map<char, int> ma;
  vector<int> pre(n + 1, 0);
  pre[0] = 1;
  ma[s[0]] = 1;

  for (int i = 1; i < n; i++) {
    if (ma[s[i]] == 0) {
      pre[i] = pre[i - 1] + 1;
      ma[s[i]]++;
    } else
      pre[i] = pre[i - 1];
  }

  ma.clear();
  vector<int> suf(n + 1, 0);
  suf[n - 1] = 1;
  ma[s[n - 1]] = 1;

  for (int i = n - 2; i >= 0; i--) {
    if (ma[s[i]] == 0) {
      suf[i] = suf[i + 1] + 1;
      ma[s[i]]++;
    } else
      suf[i] = suf[i + 1];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, (pre[i] + suf[i + 1]));
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
