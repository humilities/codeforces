#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  string s;
  string t;

  cin >> s >> t;
  int len = s.size();
  int len2 = t.size();

  string pre = t.substr(0, len);
  string suf = t.substr(len2 - len, len2);

  // cout << pre << " " << suf << "\n";
  // cout << len2 - len << " " << len << "\n";

  if (pre == s && suf == s)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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
