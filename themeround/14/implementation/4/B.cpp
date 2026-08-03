#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  char c;
  cin >> n >> c;

  string s;
  cin >> s;
  s += s;

  if (c == 'g') {
    cout << 0 << "\n";
    return;
  }

  int ans = 0;
  int cur = 0;
  for (int i = 2 * n - 1; i >= 0; i--) {
    if (s[i] == 'g') {
      cur = i;
      continue;
    }

    if (s[i] == c)
      ans = max(ans, cur - i + 1);
  }

  cout << ans - 1 << "\n";
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
