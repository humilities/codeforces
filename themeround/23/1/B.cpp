#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  if (s[0] == 's')
    s[0] = '.';
  if (s[n - 1] == 'p')
    s[n - 1] = '.';

  bool f1 = false;
  bool f2 = false;

  for (char c : s) {
    if (c == 's')
      f1 = true;
    else if (c == 'p')
      f2 = true;
  }

  if (f1 && f2)
    cout << "NO" << "\n";
  else
    cout << "YES" << "\n";
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
