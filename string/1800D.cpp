#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int cnt = n - 1;
  for (int i = 2; i < n; i++) {
    if (s[i - 2] == s[i])
      cnt--;
  }

  cout << cnt << endl;
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
