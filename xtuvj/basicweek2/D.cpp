#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  int pos = -1;
  for (int i = 0; i < s.length(); i++) {
    int val = s[i] - '0';
    if (val % 2 == 0) {
      if (val < s[s.length() - 1] - '0') {
        pos = i;
        break;
      } else {
        pos = max(pos, i);
      }

      // cout << s[s.length() - 1] - '0' << endl;
    }
  }

  if (pos == -1) {
    cout << "-1" << endl;
    return;
  }

  swap(s[pos], s[s.length() - 1]);

  cout << s << endl;
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
