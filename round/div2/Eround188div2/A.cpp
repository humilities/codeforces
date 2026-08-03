#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int cnt = 0;
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'L')
      break;

    cnt++;
  }

  cout << cnt + 1 << endl;
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
