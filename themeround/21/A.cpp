#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> one;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      one.push_back(i);
  }

  int m = one.size();
  int ans = 0;
  for (int i = 0; i < m - 1; i++)
    ans = max(ans, one[i + 1] - one[i] - 1);

  int las = one[0] + (n - 1 - one[m - 1]);
  cout << max(ans, las) << "\n";
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
